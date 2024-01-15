/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:51:06 by eun               #+#    #+#             */
/*   Updated: 2024/01/15 15:28:16 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# define PRINTF_DEC "0123456789"
# define PRINTF_HEX_ALL_L "0123456789abcdef"
# define PRINTF_HEX_ALL_U "0123456789ABCDEF"

char	*ft_itoa_base(long long n, int base, int up);
int		print_str(char *str, char format);

#endif