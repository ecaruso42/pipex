/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:35:07 by ecaruso           #+#    #+#             */
/*   Updated: 2023/02/05 17:17:29 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lenght_string(int n)
{
	long int	number;
	int			len;

	number = n;
	len = 1;
	if (number < 0)
	{
		len++;
		number = -number;
	}
	while (number >= 10)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*stringa;
	long	number;
	long	len;

	len = lenght_string(n);
	number = n;
	stringa = (char *)malloc(len + 1);
	if (!stringa)
		return (NULL);
	stringa[len--] = '\0';
	if (number < 0)
	{
		number = -number;
		stringa[0] = '-';
	}
	while (number >= 10)
	{
		stringa[len--] = 48 + (number % 10);
		number /= 10;
	}
	if (number >= 0 && number < 10)
		stringa[len] = 48 + (number % 10);
	return (stringa);
}
