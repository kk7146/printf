/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:51:06 by eun               #+#    #+#             */
/*   Updated: 2024/01/17 12:59:49 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# define PRINTF_DEC "0123456789"
# define PRINTF_HEX_ALL_L "0123456789abcdef"
# define PRINTF_HEX_ALL_U "0123456789ABCDEF"

int	ft_itoa_base(long num, int base, int up);
int	ft_itoa_unsigned_base(unsigned long num, int base);

#endif