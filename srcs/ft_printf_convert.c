/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:55:21 by eun               #+#    #+#             */
/*   Updated: 2024/01/15 15:31:44 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_convert.h"
#include "../includes/ft_printf_utils.h"
#include "../includes/libft.h"

char	*convert_ptr(va_list *arg_lst, int up)
{
	char				*str;
	char				*result;
	unsigned long long	buf;

	buf = (unsigned long long)va_arg(*arg_lst, unsigned long long);
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

char	*convert_pct(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}

char	*convert_int(va_list *arg_lst, int up)
{
	char		*str;
	long long	buf;

	buf = (long long)va_arg(*arg_lst, int);
	if (!buf)
		return (NULL);
	str = ft_itoa_base(buf, 16, up);
	if (!str)
		return (NULL);
	return (str);
}

char	*convert_hex(va_list *arg_lst, int up)
{
	char		*str;
	long long	buf;

	buf = (long long)va_arg(*arg_lst, long long);
	if (!buf)
		return (NULL);
	str = ft_itoa_base(buf, 16, up);
	if (!str)
		return (NULL);
	return (str);
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

char	*convert_char(va_list *arg_lst)
{
	char	*str;
	char	buf;

	buf = (char)va_arg(*arg_lst, int);
	if (!buf)
		return (NULL);
	str = (char *)malloc(sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (!str)
		return (NULL);
	str[0] = buf;
	str[1] = '\0';
	return (str);
}