/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:55:21 by eun               #+#    #+#             */
/*   Updated: 2024/01/17 12:58:59 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_print.h"
#include "../includes/ft_printf_utils.h"
#include "../includes/libft.h"

int	print_ptr(va_list arg_lst)
{
	unsigned long long	buf;
	int					temp;

	buf = (unsigned long long)va_arg(arg_lst, void *);
	if (!buf)
		return (-1);
	if (write(1, &"0x", 2) == -1)
		return (-1);
	temp = ft_itoa_unsigned_base(buf, 16);
	if (temp == -1)
		return (-1);
	return (temp + 2);
}

int	print_int_u(va_list arg_lst)
{
	unsigned long long	buf;

	buf = (unsigned long long)va_arg(arg_lst, void *);
	return (ft_itoa_unsigned_base(buf, 10));
}

int	print_int(va_list arg_lst, int up)
{
	long long	buf;

	buf = (long long)va_arg(arg_lst, int);
	return (ft_itoa_base(buf, 10, up));
}

int	print_hex(va_list arg_lst, int up)
{
	long long	buf;

	buf = (long long)va_arg(arg_lst, long long);
	return (ft_itoa_base(buf, 16, up));
}

int	print_string(va_list arg_lst)
{
	char	*buf;
	int		len;

	buf = va_arg(arg_lst, char *);
	len = ft_strlen(buf);
	return (write(1, buf, len));
}

int	print_char(va_list arg_lst)
{
	char	buf;

	buf = (char)va_arg(arg_lst, int);
	return (write(1, &buf, 1));
}