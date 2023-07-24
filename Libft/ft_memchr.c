/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:27:25 by ecaruso           #+#    #+#             */
/*   Updated: 2023/01/26 16:02:17 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	p;

	ptr = (unsigned char *) s;
	i = 0;
	p = c;
	while (i < n)
	{
		if (ptr[i] == p)
		{
			return ((void *)ptr + i);
		}
		i++;
	}
	return (0);
}
