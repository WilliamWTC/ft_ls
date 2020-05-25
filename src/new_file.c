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

	if (!file)
		file = new_file(file_name, stats);
	else
	{
		tmp = file;
		while (tmp->next)
			tmp = tmp->next;

		tmp->next = new_file(file_name, stats);
	}
	return (file);
}