/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabitse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:05:53 by lmabitse          #+#    #+#             */
/*   Updated: 2019/06/13 13:05:22 by lmabitse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;

	i = 0;
	a = (char*)dst;
	b = (char*)src;
	while (i < n)
	{
		a[i] = b[i];
		if ((unsigned char)b[i] == (unsigned char)c)
			return ((char*)dst + 1 + i);
		i++;
	}
	return (NULL);
}
