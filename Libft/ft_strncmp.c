/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:03:38 by ecaruso           #+#    #+#             */
/*   Updated: 2023/02/10 17:49:17 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	i = 0;
	while ((ptr1[i] || ptr2[i]) && i < n)
	{
		if (ptr1[i] > ptr2[i])
		{
			return (1);
		}
		else if (ptr1[i] < ptr2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
