/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:42:29 by chanwoki          #+#    #+#             */
/*   Updated: 2023/01/27 15:26:59 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx/mlx.h"
#include "libft/libft.h"

#define KEY_ESC				53
#define KEY_W				13
#define KEY_S				1
#define	PRESS_RED_BUTTON	17
// 각 키보드를 눌렀을때의 전달값

typedef struct s_param{
	int		x;
	int		y;
}				t_param;
// 값을 저장할 구조체
void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}
// 구조체를 생성하고 값을 초기설정 해줌

int key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->x++;
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_ESC) //ESC를 눌렀을때
		exit (0);
	printf("x: %d\n", param->x);
	return (0);
}

int ft_close(void)
{
	exit (0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_param	param;

	param_init(&param);
	mlx = mlx_init();
    //소프트웨어와 디스플레이 간의 연결을 초기화하기 위해 mlx_init()을 사용
	win = mlx_new_window(mlx, 500, 500, "타이틀바 문자열");
    // 새로운 윈도우를 스크린 위에 생성해주는 함수

	printf("---------------------------------------\n");
	printf("Start x = 3\n");
	mlx_key_hook(win, &key_press, &param);
	// 키보드의 입력을 받아 keypress 함수를 실행시키고 param의 매개변수를 활용함
	mlx_hook(win, PRESS_RED_BUTTON, 0, &ft_close, &param);
    // 여러 종류의 입력을 받아 함수를 실행시킴
    // 17은 좌측상단의 끄기버튼을 눌렀을때 실행하도록 설정해줌
	mlx_loop(mlx);
    // 키보드나 마우스로부터 이벤트를 받기위해 이벤트를 수신하는 함수,
    // 이벤트를 지속적으로 받기위해 무한루프임
}
