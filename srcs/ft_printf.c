/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:06:23 by donson            #+#    #+#             */
/*   Updated: 2024/01/11 17:18:23 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdarg.h>
#include <stdio.h>//지워

char	*convert_ptr(va_list *arg_lst, int up)
{
	char		*str;
	char		*result;
	long long	buf;

	buf = (long long)va_arg(*arg_lst, long long);
	if (!buf)
		return (NULL);
	str = ft_itoa_base(buf, 16, up);
	if (!str)
		return (NULL);
	result = ft_strjoin("0x", str);
	free(str);
	if (!result)
		return (NULL);
	return (result);
}

char	*convert_string(va_list *arg_lst)
{
	char	*str;
	char	*buf;

	buf = va_arg(*arg_lst, char *);
	if (!buf)
		return (NULL);
	str = ft_strdup(buf);
	if (!str)
		return (NULL);
	return (str);
}

static char	*convert_char(va_list *arg_lst)
{
	char	*str;
	char	buf;

	buf = (char)va_arg(*arg_lst, int);
	if (!buf)
		return (NULL);
	str = (char *)malloc(sizeof(char) + 1);
	if (!str)
		return (NULL);
	printf("%s", str);
	if (!str)
		return (NULL);
	str[0] = buf;
	str[1] = '\0';
	return (str);
}

static void	print_str(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	i = ft_strlen(str);
	write(1, str, i);
}

static char	*return_args(va_list *arg_lst, const char format)
{
	if (format == PRINTF_CHAR)
		return (convert_char(arg_lst));
	else if (format == PRINTF_STR)
		return (convert_string(arg_lst));
	else if (format == PRINTF_PTR)
		return (convert_ptr(arg_lst, 0));
	return (NULL);
}

int	print_format(va_list arg_lst, const char *format)
{
	long long	i;
	char		*str;

	i = -1;
	while (format[++i])
	{
		if (format[i] == PRINTF_PCT)
		{
			str = return_args(&arg_lst, format[++i]);
			print_str(str);
			if (!str)
				continue ;
			free(str);
		}
		else
			write(1, &format[i], 1);
	}
	va_end(arg_lst);
	return (i);
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
