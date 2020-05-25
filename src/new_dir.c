#include "ft_ls.h"

t_dirs	*new_dir(char *path)
{
	t_dirs	*new;

	new = malloc(sizeof(t_dirs));
	new->dirname = ft_strdup(path);
	new->next = NULL;
	return (new);
}

t_dirs	*add_dir(char *path, t_dirs *dirs)
{
	t_dirs	*lst;
	t_dirs	*tmp;

	if (dirs == NULL)
		dirs = new_dir(path);
	else
	{
		lst = dirs;
		while (lst)
		{
			tmp = lst;
			lst = lst->next;
		}
		tmp->next = new_dir(path);
	}
	return (dirs);
}

void	free_dir(t_dirs **dirs)
{
	t_dirs	*lst;
	t_dirs	*next;

	lst = *dirs;
	while (lst)
	{
		next = lst->next;
		ft_strdel(&lst->dirname);
		free(lst);
		lst = next;
	}
}