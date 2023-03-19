#include <stdio.h>

int main()
{
	int	size = 6;
	int	i = 0;
	int	z = 0;
	int	flag = 0;

	while (z < size)
	{
		printf("i is %d\n", i);
		if (flag == 1)
			i--;
		else
			i++;
		if (i > (size/2))
		{
			flag = 1;
			if (size % 2 == 1)
				i--;
			else
				i -= 2;
		}
		z++;
	}
}
