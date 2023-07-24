/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:03:55 by ecaruso           #+#    #+#             */
/*   Updated: 2023/01/24 16:40:39 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*str1;
	size_t			i;

	i = 0;
	str = (unsigned char *)dst;
	str1 = (unsigned char *)src;
	if ((void *)dst == 0 && (void *)src == 0)
	{
		return (0);
	}
	while (i < len)
	{
		str[i] = str1[i];
		i++;
	}
	return (dst);
}
