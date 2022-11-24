#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int main()
{
	printf("%x\n", 123);
	printf("%X\n", 123);
	printf("%x\n", -123);	
	printf("%X\n", -123);
	
	ft_printhex(123, 1);
	ft_putchar_fd('\n', 1);
	ft_printhex(123, 2);
	ft_putchar_fd('\n', 1);
	ft_printhex(-123, 1);
	ft_putchar_fd('\n', 1);
	ft_printhex(-123, 2);
	ft_putchar_fd('\n', 1);

}
