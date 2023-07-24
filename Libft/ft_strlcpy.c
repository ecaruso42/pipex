/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:59:46 by ecaruso           #+#    #+#             */
/*   Updated: 2023/02/10 17:42:58 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	a;
	unsigned int	b;

	b = ft_strlen(src);
	a = 0;
	if (size != 0)
	{
		while (src[a] && a < size - 1)
		{
			dest[a] = src[a];
			a++;
		}
		dest[a] = '\0';
	}
	return (b);
}
