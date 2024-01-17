/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:05:37 by eun               #+#    #+#             */
/*   Updated: 2024/01/17 13:04:22 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"
#include <stdlib.h>

int	ft_itoa_unsigned_base(unsigned long num, int base)
{
	unsigned long long	temp_num;
	int					len;

	temp_num = (unsigned long long)num;
	len = 0;
	while (temp_num >= (unsigned long long)base)
	{
		if (write(1, &PRINTF_HEX_ALL_L[temp_num % base], 1) == -1)
			return (-1);
		temp_num /= base;
		len++;
	}
	if (write(1, &PRINTF_HEX_ALL_L[temp_num], 1) == -1)
		return (-1);
	len++;
	return (len);
}

static char	print_int(long long num, int up)
{
	if (up)
	{
		if (write(1, &PRINTF_HEX_ALL_U[num], 1) == -1)
			return (-1);
	}
	else
		if (write(1, &PRINTF_HEX_ALL_L[num], 1) == -1)
			return (-1);
	return (1);
}

int	ft_itoa_base(long num, int base, int up)
{
	long long	temp_num;
	int			len;

	temp_num = (long long)num;
	len = 0;
	if (temp_num < 0)
	{
		temp_num *= -1;
		if (write(1, "-", 1) == -1)
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
