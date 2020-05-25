/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabitse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 09:37:24 by lmabitse          #+#    #+#             */
/*   Updated: 2019/06/12 16:53:34 by lmabitse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char *original;

	original = dst;
	dst = &dst[ft_strlen(dst)];
	while (*src != 0 && n > 0)
	{
		*dst++ = *src++;
		n--;
	}
	*dst = 0;
	return (original);
}
