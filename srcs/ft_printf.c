/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:06:23 by donson            #+#    #+#             */
/*   Updated: 2024/01/17 13:06:06 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_print.h"
#include "../includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

static int	print_args(va_list arg_lst, const char format)
{
	if (format == PRINTF_CHAR)
		return (print_char(arg_lst));
	else if (format == PRINTF_STR)
		return (print_string(arg_lst));
	else if (format == PRINTF_PTR)
		return (print_ptr(arg_lst));
	else if (format == PRINTF_INT_D || format == PRINTF_INT_I)
		return (print_int(arg_lst, 0));
	else if (format == PRINTF_INT_U)
		return (print_int_u(arg_lst));
	else if (format == PRINTF_HEX_L)
		return (print_hex(arg_lst, 0));
	else if (format == PRINTF_HEX_U)
		return (print_hex(arg_lst, 1));
	else if (format == PRINTF_PCT)
		return (write(1, "%", 1));
	return (-1);
}

int	print_format(va_list arg_lst, const char *format)
{
	long long	i;
	int			count;
	int			temp;

	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == PRINTF_PCT)
		{
			temp = print_args(arg_lst, format[++i]);
			if (temp == -1)
				return (-1);
			count += temp;
			continue ;
		}
		if (write(1, &format[i], 1) == -1)
			return (-1);
		count++;
	}
	va_end(arg_lst);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg_lst;

	va_start(arg_lst, format);
	if (!format)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		va_end(arg_lst);
		return (-1);
	}
	return (print_format(arg_lst, format));
}
