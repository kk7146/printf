/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:06:23 by donson            #+#    #+#             */
/*   Updated: 2024/01/15 15:26:29 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_convert.h"
#include "../includes/ft_printf_utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>//지워

static char	*return_args(va_list *arg_lst, const char format)
{
	if (format == PRINTF_CHAR)
		return (convert_char(arg_lst));
	else if (format == PRINTF_STR)
		return (convert_string(arg_lst));
	else if (format == PRINTF_PTR)
		return (convert_ptr(arg_lst, 0));
	else if (format == PRINTF_INT_D || format == PRINTF_INT_I
		|| format == PRINTF_INT_U)
		return (convert_int(arg_lst, 0));
	else if (format == PRINTF_HEX_L)
		return (convert_hex(arg_lst, 0));
	else if (format == PRINTF_HEX_U)
		return (convert_hex(arg_lst, 1));
	else if (format == PRINTF_PCT)
		return (convert_pct());
	return (NULL);
}

int	print_format(va_list arg_lst, const char *format)
{
	long long	i;
	int			count;
	char		*str;

	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == PRINTF_PCT)
		{
			str = return_args(&arg_lst, format[++i]);
			count += print_str(str, format[i]);
			if (!str)
				continue ;
			free(str);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
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
		write(1, "(null)", 6);
		va_end(arg_lst);
		return (0);
	}
	return (print_format(arg_lst, format));
}
