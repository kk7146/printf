/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:06:18 by donson            #+#    #+#             */
/*   Updated: 2024/01/15 18:56:04 by donson           ###   ########.fr       */
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

int		ft_printf(const char *format, ...);

#endif