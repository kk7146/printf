/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:51:06 by eun               #+#    #+#             */
/*   Updated: 2024/01/16 14:11:45 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_NUM_H
# define FT_PRINTF_NUM_H

# define PRINTF_HEX_ALL_L "0123456789abcdef"
# define PRINTF_HEX_ALL_U "0123456789ABCDEF"

char	*ft_itoa_base(long long n, int base, int up);

#endif