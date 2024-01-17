/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:55:21 by eun               #+#    #+#             */
/*   Updated: 2024/01/16 17:41:06 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_print.h"
#include "../includes/ft_printf_ptr.h"
#include "../includes/ft_printf_num.h"
#include "../includes/libft.h"

char	*print_ptr(va_list arg_lst)
{
	char				*str;
	char				*result;
	unsigned long long	buf;

	buf = (unsigned long long)va_arg(arg_lst, void *);
	if (!buf)
		return (NULL);
	str = ft_itoa_base_ptr(buf, 16, up);
	if (!str)
		return (NULL);
	result = ft_strjoin("0x", str);
	free(str);
	if (!result)
		return (NULL);
	return (result);
}

char	*print_int_u(va_list arg_lst)
{
	char				*str;
	unsigned long long	buf;

	buf = (unsigned long long)va_arg(arg_lst, void *);
	str = ft_itoa_base_ptr(buf, 10, up);
	if (!str)
		return (NULL);
	return (str);
}

char	*print_int(va_list arg_lst, int up)
{
	char		*str;
	long long	buf;

	buf = (long long)va_arg(arg_lst, int);
	str = ft_itoa_base(buf, 10, up);
	if (!str)
		return (NULL);
	return (str);
}

char	*print_hex(va_list arg_lst, int up)
{
	char		*str;
	long long	buf;

	buf = (long long)va_arg(arg_lst, long long);
	str = ft_itoa_base(buf, 16, up);
	if (!str)
		return (NULL);
	return (str);
}

char	*print_string(va_list arg_lst)
{
	char	*str;
	int		len;

	str = va_arg(arg_lst, char *);
	len = ft_strlen(str);
	return (write(1, str, len));
}

char	*print_char(va_list arg_lst)
{
	char	buf;

	buf = (char)va_arg(arg_lst, int);
	return (write(1, &buf, 1));
}