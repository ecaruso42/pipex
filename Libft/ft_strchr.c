/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:16:48 by ecaruso           #+#    #+#             */
/*   Updated: 2023/02/10 17:21:27 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	a;

	a = 0;
	while (a < ft_strlen(s) + 1)
	{
		if (*(s + a) == (char)c)
			return ((char *)(s + a));
		a++;
	}
	return (NULL);
}
