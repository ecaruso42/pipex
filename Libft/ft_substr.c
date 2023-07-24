/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:14:10 by ecaruso           #+#    #+#             */
/*   Updated: 2023/01/30 18:21:21 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	if ((start + len) >= ft_strlen(s))
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (ptr);
	i = 0;
	while (i != len)
	{
		ptr[i] = *(s + start + i);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
