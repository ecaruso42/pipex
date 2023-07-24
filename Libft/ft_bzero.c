/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:08:06 by ecaruso           #+#    #+#             */
/*   Updated: 2023/01/21 17:55:35 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = str;
	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
}
