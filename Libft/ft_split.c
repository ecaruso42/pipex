/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:53:48 by ecaruso           #+#    #+#             */
/*   Updated: 2023/02/10 16:48:07 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char		**number_of_words;
	size_t		i;
	size_t		len;

	if (!s)
		return (0);
	i = 0;
	number_of_words = malloc(sizeof(char *) * (get_word(s, c) + 1));
	if (!number_of_words)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			number_of_words[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	number_of_words[i] = 0;
	return (number_of_words);
}
