/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:15:07 by ecaruso           #+#    #+#             */
/*   Updated: 2023/02/01 18:45:32 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]) != '\0')
		i++;
	k = ft_strlen((char *) s1);
	while (k > i && ft_strchr(set, s1[k - 1]) != '\0')
		k--;
	ptr = (char *) malloc(sizeof(*s1) * (k - i + 1));
	if (!ptr)
		return (NULL);
	while (i < k)
		ptr[j++] = s1[i++];
	ptr[j] = '\0';
	return ((char *)ptr);
}
