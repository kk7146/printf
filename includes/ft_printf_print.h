/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:56:20 by eun               #+#    #+#             */
/*   Updated: 2024/01/17 12:52:43 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINT_H
# define FT_PRINTF_PRINT_H

# include <stdarg.h>

int	print_ptr(va_list arg_lst);
int	print_int(va_list arg_lst, int up);
int	print_hex(va_list arg_lst, int up);
int	print_int_u(va_list arg_lst);
int	print_string(va_list arg_lst);
int	print_char(va_list arg_lst);

#endif