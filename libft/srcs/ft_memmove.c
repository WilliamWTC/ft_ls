/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabitse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:37:46 by lmabitse          #+#    #+#             */
/*   Updated: 2019/06/13 13:21:36 by lmabitse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *a;
	char *b;

	if (dst == NULL && src == NULL)
		return (NULL);
	a = (char*)src;
	b = (char*)dst;
	if (a < b)
		while (len--)
		{
			b[len] = a[len];
		}
	else
		ft_memcpy(b, a, len);
	return (dst);
}
