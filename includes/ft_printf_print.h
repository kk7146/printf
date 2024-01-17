/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:56:20 by eun               #+#    #+#             */
/*   Updated: 2024/01/16 17:38:22 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINT_H
# define FT_PRINTF_PRINT_H

# include <stdarg.h>

char	*convert_ptr(va_list arg_lst, int up);
char	*convert_string(va_list arg_lst);
char	*convert_char(va_list arg_lst);
char	*convert_int(va_list arg_lst, int up);
char	*convert_hex(va_list arg_lst, int up);
char	*convert_int_u(va_list arg_lst, int up);

#endif