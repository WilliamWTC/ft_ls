/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabitse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 08:39:19 by lmabitse          #+#    #+#             */
/*   Updated: 2019/06/12 16:49:52 by lmabitse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *w;

	while (n-- > 0)
	{
		w = (unsigned char*)str;
		if (*w == (unsigned char)c)
		{
			return (w);
		}
		str++;
	}
	return (NULL);
}
