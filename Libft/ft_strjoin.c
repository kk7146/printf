/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:14:43 by donson            #+#    #+#             */
/*   Updated: 2023/10/25 14:26:20 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	while ((unsigned char)s1[len_s1] != '\0')
		len_s1++;
	while ((unsigned char)s1[len_s2] != '\0')
		len_s2++;
	len_s2 = ft_strlen(s2);
	result = (char *)ft_calloc(sizeof(char), len_s1 + len_s2 + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len_s1 + 1);
	ft_strlcpy(result + len_s1, s2, len_s2 + 1);
	return (result);
}
