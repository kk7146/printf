/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:05:37 by eun               #+#    #+#             */
/*   Updated: 2024/01/16 14:42:03 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_num.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <stdlib.h>

static int	ft_itoa_len(long long nbr, int *sign, int base)
{
	long long int	nb;
	int				len;

	len = 0;
	nb = (long long int)nbr;
	*sign = 0;
	if (nbr < 0)
	{
		nb *= -1;
		*sign = 1;
		len++;
	}
	while (nb >= base)
	{
		nb /= base;
		len++;
	}
	len++;
	return (len);
}

static char	return_int(long long n, int up)
{
	if (up)
		return (PRINTF_HEX_ALL_U[n]);
	else
		return (PRINTF_HEX_ALL_L[n]);
}

static unsigned char	*ft_set_chr(int len, long long n, int base, int up)
{
	unsigned char	*chr;

	chr = (unsigned char *)malloc((len + 1) * sizeof(unsigned char));
	if (!chr)
		return (NULL);
	chr[len] = '\0';
	while (--len + 1)
	{
		if (n < 0)
		{
			n *= -1;
			(++chr)[-1] = '-';
		}
		else if (n < base)
			chr[len] = return_int(n, up);
		else
		{
			chr[len] = return_int(n % base, up);
			n /= base;
		}
	}
	return (chr);
}

char	*ft_itoa_base(long long n, int base, int up)
{
	size_t			len;
	unsigned char	*chr;
	int				sign;

	len = ft_itoa_len(n, &sign, base);
	chr = ft_set_chr(len, n, base, up);
	if (!chr)
		return (NULL);
	if (sign)
		chr--;
	return ((char *)chr);
}
