/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabitse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 09:55:50 by lmabitse          #+#    #+#             */
/*   Updated: 2019/06/12 16:47:24 by lmabitse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rec_path(char *fullpath)
{
	ft_putstr(fullpath);
	ft_putendl(":");
}

void	path(char *s1, char *s2, char **path)
{
	char	*tmp;

	tmp = ft_strjoin(s1, "/");
	*path = ft_strjoin(tmp, s2);
	ft_strdel(&tmp);
}
