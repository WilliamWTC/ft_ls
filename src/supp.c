# include "ft_ls.h"

char filetype(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISDIR(mode))
		return ('d');
	else
		return ('-');
}

char *rec_att(struct stat stats)
{
	char  attr[1];
	attr[0] = filetype(stats.st_mode);
	attr[1] = '\0';
	return (ft_strdup(attr));
}

int can_recurse(t_file *file)
{
    if(file->d[0] == 'd' && !ft_strequ(file->name, ".") && !ft_strequ(file->name, ".."))
		return 1;
	return 0;
}

void free_rec(char *str1, char *str2)
{
	ft_strdel(&str1);
	ft_strdel(&str2);
}

void		free_list(t_file **file)
 {
 	t_file	*tmp;
 	t_file	*next;

 	tmp = *file;
 	while (tmp)
 	{
 		next = tmp->next;
 		ft_strdel(&tmp->d);
    	ft_strdel(&tmp->name);
    	tmp->time = 0;
    	tmp->next = NULL;
 		free(tmp);
 		tmp = next;
 	}
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