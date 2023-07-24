/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:52:51 by ecaruso           #+#    #+#             */
/*   Updated: 2023/01/29 15:23:08 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)str);
	while (i < len && str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0' && (i + j) < len)
			j++;
		if (to_find[j] == '\0')
			return ((char *) str + i);
		i++;
		j = 0;
	}
	return (0);
}
