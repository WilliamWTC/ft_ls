/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabitse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:26:17 by lmabitse          #+#    #+#             */
/*   Updated: 2019/06/13 13:06:05 by lmabitse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char *p;
	const unsigned char *f;
	size_t				w;

	w = 0;
	p = (unsigned char*)str1;
	f = (unsigned char*)str2;
	while (w < n)
	{
		if (p[w] != f[w])
			return ((unsigned char)p[w] - (unsigned char)f[w]);
		w++;
	}
	return (0);
}
