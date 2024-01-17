/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:51:06 by eun               #+#    #+#             */
/*   Updated: 2024/01/15 18:45:14 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PTR_H
# define FT_PRINTF_PTR_H

# define PRINTF_DEC "0123456789"
# define PRINTF_HEX_ALL_L "0123456789abcdef"
# define PRINTF_HEX_ALL_U "0123456789ABCDEF"

char	*ft_itoa_base_ptr(unsigned long long n, int base, int up);

#endif