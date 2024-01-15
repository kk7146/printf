/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:56:20 by eun               #+#    #+#             */
/*   Updated: 2024/01/15 15:18:39 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONVERT_H
# define FT_PRINTF_CONVERT_H

# include <stdarg.h>

char	*convert_ptr(va_list *arg_lst, int up);
char	*convert_string(va_list *arg_lst);
char	*convert_char(va_list *arg_lst);
char	*convert_int(va_list *arg_lst, int up);
char	*convert_hex(va_list *arg_lst, int up);
char	*convert_pct(void);

#endif