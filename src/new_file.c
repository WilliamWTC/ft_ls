#include "ft_ls.h"

t_file		*new_file(char *file_name, struct stat stats)
 {
 	t_file	*new;

 	new = malloc(sizeof(t_file));
	new->d = rec_att(stats);
 	new->name = ft_strdup(file_name);
 	new->time = stats.st_mtime;
 	new->next = NULL;
 	return (new);
 }

t_file		*add_file(t_file *file, char *file_name, struct stat stats)
{
	t_file	*tmp;
	t_file	*new;

	tmp = file;
	new = new_file(file_name, stats);
	if (!file)
		return (new);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (file);
}

 static void	free_file(t_file *file)
 {
	ft_strdel(&file->d);
    ft_strdel(&file->name);
    file->time = 0;
    file->next = NULL;
 	free(file);
 }

 void		free_list(t_file **file)
 {
 	t_file	*tmp;
 	t_file	*next;

 	tmp = *file;
 	while (tmp)
 	{
 		next = tmp->next;
 		free_file(tmp);
 		tmp = next;
 	}
 }