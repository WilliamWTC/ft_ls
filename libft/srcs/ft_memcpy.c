/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabitse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:13:30 by lmabitse          #+#    #+#             */
/*   Updated: 2019/06/13 13:21:17 by lmabitse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *p;
	char *f;

	if (dst == NULL && src == NULL)
		return (NULL);
	p = (char*)src;
	f = (char*)dst;
	while (n--)
	{
		*f++ = *p++;
	}
	return (dst);
}
