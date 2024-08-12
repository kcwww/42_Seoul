#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

/*********************************************************************************************************************************************/

/* 1. 클라이언트 정보와 버퍼 정보 초기화 */

// 클라이언트 구조체 정의
typedef struct s_client
{
    int     id;
    char    msg[300000];
}   t_client;


t_client    clients[1024]; // 최대 1024 명  클라이언트 접속 가능
fd_set      read_set, write_set, current; // select 함수와 연관, 이벤트를 감지할 파일 디스크립터 집합 - 읽기, 쓰기, 현재
int         maxfd = 0, gid = 0; // 현재 서버에서 사용 중인 가장 큰 파일 디스크립터를 저장합니다. 이는 select 함수에서 파일 디스크립터 집합을 처리할 때 필요합니다. gid = 클라이언트의 고유 ID를 관리하는 변수입니다. 클라이언트가 접속할 때마다 증가합니다.
char        send_buffer[300000], recv_buffer[300000]; // 서버가 클라이언트에게 보낼 메시지를 저장하는 버퍼와 서버가 클라이언트로부터 받은 메세지를 저장하는 버퍼
/*********************************************************************************************************************************************/


/*********************************************************************************************************************************************/

/* 2.err 기능과 broadcast 기능 추가 */


// err 함수 메세지가 없는 경우 기본적으로 Fatal error
void    err(char  *msg)
{
    if (msg)
        write(2, msg, strlen(msg));
    else
        write(2, "Fatal error", 11);
    write(2, "\n", 1);
    exit(1);
}


// broadcast - send_buffer에 저장된 메시지를 모든 클라이언트에게 전송하는 역할. 단, except로 지정된 파일 디스크립터는 제외
void    send_to_all(int except)
{
    for (int fd = 0; fd <= maxfd; fd++) // 파일 디스크립터 확인
    {
        if  (FD_ISSET(fd, &write_set) && fd != except) // 파일 디스크립터 fd가 write_set 집합에 포함되어 있는지 확인 (쓰기 상태인지)
            if (send(fd, send_buffer, strlen(send_buffer), 0) == -1) // send_buffer의 내용을 fd에 보냅니다.
                err(NULL);
    }
}

/*********************************************************************************************************************************************/



/* 3. main 함수 인자 예외처리 까먹지 않기 ! */
int     main(int ac, char **av)
{
    if (ac != 2) // 인자 예외처리
        err("Wrong number of arguments");

/*********************************************************************************************************************************************/

    /* 4.서버 소켓을 설정하고 초기화 */

    struct sockaddr_in  serveraddr; // 서버의 주소 정보를 저장하는 구조체입니다. 이 구조체는 IP 주소와 포트 번호 등을 포함하여 서버의 소켓 주소를 정의합니다.
    socklen_t           len; // accept 함수 호출 시 소켓 주소의 크기를 저장하는 데 사용됩니다. 주로 accept 호출 전에 주소 구조체의 크기를 저장하는 데 사용됩니다.
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);// 새로운 소켓을 생성한다. AF_INET: IPv4 주소 체계를 사용, SOCK_STREAM: 신뢰성 있는 데이터 전송을 제공하는 스트림 소켓을 생성, 0: 프로토콜을 자동으로 선택 (기본적으로 TCP)

    if (serverfd == -1) err(NULL); // 소켓 생성 실패 예외처리
    maxfd = serverfd; // 현재 가장 큰 파일 디스크립터를 serverfd로 지정

    FD_ZERO(&current); // current 파일 디스크립터 집합을 초기화. 모든 비트가 0으로 설정
    FD_SET(serverfd, &current); // serverfd를 current 파일 디스크립터 집합에 추가합니다. 이 집합은 select 호출 시 읽기 가능한 파일 디스크립터를 확인하는 데 사용

    // 클라이언트 배열과 서버 구조체의 모든 바이트를 0 으로 초기화
    bzero(clients, sizeof(clients)); 
    bzero(&serveraddr, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET; // sin_family 필드를 AF_INET으로 설정하여 IPv4 주소 체계를 사용하도록 지정
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); // sin_addr.s_addr 필드를 INADDR_ANY로 설정하여 서버가 모든 네트워크 인터페이스에서 오는 연결 요청을 수락하도록 지정 (htonl은 호스트 바이트 순서를 네트워크 바이트 순서로 변환하는 함수 32비트)
    serveraddr.sin_port = htons(atoi(av[1])); // 첫 번째 인자로 전달된 포트 번호를 사용 (htons는 호스트 바이트 순서를 네트워크 바이트 순서로 변환 16비트)

/*********************************************************************************************************************************************/

    /* 5. 포트에 바인딩하고, 클라이언트 연결을 대기하는 상태로 설정 */
    
    // 서버 주소를 파일 디스크립터에 바인딩
    if (bind(serverfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1 || listen(serverfd, 100) == -1) // listen 은 수신상태로 설정, 100 은 대기열의 크기
        err(NULL);

    while (1) // 무한 루프 시작. 서버가 계속해서 클라이언트의 요청을 처리하고 응답할 수 있도록 유지
    {

        /*********************************************************************************************************************************************/

        /* 6. 파일 디스크립터 집합 초기화 및 select 호출: 현재 상태를 복사하고, 이벤트를 기다림 */

        // read_set과 write_set을 current 상태로 설정
        read_set = write_set = current; // 현재 파일 디스크립터 집합 상태를 read_set과 write_set으로 복사하여, select 호출 시 사용할 준비를 합니다.

        // select 호출: 파일 디스크립터 집합에서 읽기 및 쓰기 가능한 파일 디스크립터를 기다립니다.
        if (select(maxfd + 1, &read_set, &write_set, 0, 0) == -1) continue; // select 호출이 실패하면, 루프의 시작으로 돌아갑니다. (continue)

        /*********************************************************************************************************************************************/


        /* 7. 파일 디스크립터 처리 읽기 이벤트가 발생한 파일 디스크립터를 확인 */

        // 모든 파일 디스크립터를 검사하여 이벤트가 발생한 것을 처리
        for (int fd = 0; fd <= maxfd; fd++)
        {
            // 현재 파일 디스크립터에서 읽기 이벤트가 발생했는지 확인
            if (FD_ISSET(fd, &read_set))
            {



                /* 8. 서버 소켓에서의 이벤트 */

                if (fd == serverfd) // 서버 소켓에서 읽기 이벤트가 발생한 경우 - 새로운 클라이언트 연결
                {
                    // 새로운 클라이언트 연결을 수락
                    int clientfd = accept(serverfd, (struct sockaddr *)&serveraddr, &len); // 클라이언트 연결을 수락하고 새로운 클라이언트 소켓을 반환합니다.
                    if (clientfd == -1) continue; // accept 호출이 실패 예외처리 (continue 로 프로그램이 꺼지지 않게)

                    // 새로운 클라이언트 소켓 파일 디스크립터가 현재 최대 파일 디스크립터보다 크면 maxfd 값 변경
                    if (clientfd > maxfd) maxfd = clientfd;

                    // 클라이언트 정보를 초기화하고 현재 파일 디스크립터 집합에 추가
                    clients[clientfd].id = gid++; // 클라이언트에 고유 ID를 부여
                    FD_SET(clientfd, &current); // 새로운 클라이언트 소켓 파일 디스크립터를 current 집합에 추가

                    // 새로운 클라이언트가 접속했음을 모든 클라이언트에게 전달
                    sprintf(send_buffer, "server: client %d just arrived\n", clients[clientfd].id); // 접속 메시지를 생성
                    send_to_all(clientfd);
                }


                /* 9. 클라이언트 소켓에서의 이벤트 */

                else // 클라이언트 소켓에서 읽기 이벤트가 발생한 경우
                {
                    // fd 클라이언트로부터 데이터를 수신
                    int ret = recv(fd, recv_buffer, sizeof(recv_buffer), 0);


                    // 수신된 데이터가 없거나 오류가 발생한 경우
                    if (ret <= 0) 
                    {
                        // 클라이언트가 연결을 종료했음을 모든 클라이언트에게 전달
                        sprintf(send_buffer, "server: client %d just left\n", clients[fd].id); // 클라이언트가 나갔다는 메시지 생성
                        send_to_all(fd);

                        // 해당 클라이언트 소켓을 current 집합에서 제거하고 소켓을 닫기
                        FD_CLR(fd, &current); // 파일 디스크립터 집합에서 클라이언트 소켓을 제거
                        close(fd); // 클라이언트 소켓을 닫기

                        // 클라이언트의 메시지 버퍼를 초기화합니다.
                        bzero(clients[fd].msg, strlen(clients[fd].msg)); // 클라이언트의 메시지 버퍼를 비웁니다.
                    }



                    else // 수신된 데이터가 있는 경우
                    {
                        // 수신된 데이터를 클라이언트의 메시지 버퍼에 추가
                        for (int i = 0, j = strlen(clients[fd].msg); i < ret; i++, j++)
                        {
                            clients[fd].msg[j] = recv_buffer[i];
                            if (clients[fd].msg[j] == '\n') // 줄 바꿈 문자는 메세지가 끝났음을 의미
                            {
                                clients[fd].msg[j] = '\0'; // 메시지 끝 처리

                                // 클라이언트의 메시지를 모든 클라이언트에게 전달
                                sprintf(send_buffer, "client %d: %s\n", clients[fd].id, clients[fd].msg); // 클라이언트 메세지 생성
                                send_to_all(fd);

                                // 클라이언트의 메시지를 보낸 뒤, 버퍼 초기화
                                bzero(clients[fd].msg, strlen(clients[fd].msg)); // 메시지 버퍼를 비웁니다.
                                j = -1; // 메시지 버퍼의 인덱스를 초기화 바로 다음 
                            }
                        }
                    }
                }
                break; // 현재 파일 디스크립터에서 이벤트가 처리된 후, 루프를 종료합니다.
            }
        }
    }

    return (0);
}
