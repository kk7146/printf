#include <stdio.h>
#include "./includes/ft_printf.h"

int main()
{
	int a;
	printf("%c %s %p\n", '0' - 256, NULL, (void *)-14523);
	ft_printf("%c %s %p\n", '0' - 256, NULL, (void *)-14523);
}