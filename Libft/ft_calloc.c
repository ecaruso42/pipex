/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:28:20 by ecaruso           #+#    #+#             */
/*   Updated: 2023/01/30 16:08:09 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (NULL);
	if (!ptr || (count == SIZE_MAX && size == SIZE_MAX))
		return (0);
	ft_bzero (ptr, count * size);
	return (ptr);
}
