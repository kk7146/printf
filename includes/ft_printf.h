/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:06:18 by donson            #+#    #+#             */
/*   Updated: 2024/01/11 17:24:14 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PRINTF_CHAR 'c'
# define PRINTF_STR 's'
# define PRINTF_PTR 'p'
# define PRINTF_INT_D	'd'
# define PRINTF_INT_I	'i'
# define PRINTF_INT_U	'u'
# define PRINTF_HEX_L	'x'
# define PRINTF_HEX_U	'X'
# define PRINTF_PCT	'%'
# define PRINTF_ALL	"cspdiuxX%"
# define PRINTF_DEC "0123456789"
# define PRINTF_HEX_ALL_L "0123456789abcdef"
# define PRINTF_HEX_ALL_U "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
char	*ft_itoa_base(long long n, int base, int up);

#endif