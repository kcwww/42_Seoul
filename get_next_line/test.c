#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

 int main()
 {
	int	fd;

	fd = open("test", O_RDONLY);
	printf("%s\n",get_next_line(fd));
 }
