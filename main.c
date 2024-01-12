#include <stdio.h>
#include "./includes/ft_printf.h"

int main()
{
	int a;
	printf("%c %s %p\n", 'a', "asda", &a);
	ft_printf("%c %s %p\n", 'a', "asda", &a);
}