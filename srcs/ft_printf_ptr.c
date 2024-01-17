/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:05:37 by eun               #+#    #+#             */
/*   Updated: 2024/01/16 18:54:57 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include "../includes/ft_printf_ptr.h"
#include <stdlib.h>

char	*ft_itoa_unsigned_base(unsigned long num, int base)
{
	unsigned long long	temp_num;
	int					len;
	int					temp_len;

	temp_num = (unsigned long long)num;
	len = 0;
	while (temp_num >= base)
	{
		if (write(1, PRINTF_HEX_ALL_L[temp_num % base], 1) == -1)
			return (-1);
		temp_num /= base;
		len++;
	}
	if (write(1, PRINTF_HEX_ALL_L[temp_num], 1) == -1)
		return (-1);
	len++;
	return (len);
}

static char	print_int(long long n, int up)
{
	if (up)
		if (write(1, PRINTF_HEX_ALL_U[temp_num], 1) == -1)
			return (-1);
	else
		if (write(1, PRINTF_HEX_ALL_L[temp_num], 1) == -1)
			return (-1);
	return (1);
}

char	*ft_itoa_base(long num, int base, int up)
{
	long long	temp_num;
	int			len;
	int			temp_len;

	temp_num = (long long)num;
	len = 0;
	if (temp_num < 0)
	{
		temp_num *= -1;
		if (write(1, &'-', 1) == -1)
			return (-1);
		len++;
	}
	while (temp_num >= base)
	{
		if (print_int(temp_num % base, up) == -1)
			return (-1);
		temp_num /= base;
		len++;
	}
	if (print_int(temp_num, up) == -1)
		return (-1);
	len++;
	return (len);
}
