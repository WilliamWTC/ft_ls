#include "ft_ls.h"

void	print_file(t_file *file)
{
 	while (file != NULL)
 	{
 		ft_putendl(file->name);
 		file = file->next;
 	}
 }

void	ls_print(char *folder, int flags)
{
	t_file			*file;

	file = NULL;
	build_path(&file, folder, flags);
	sort_list(&file, flags);
	print_file(file);
	if (flags & LS_RR)
		ls_recur(&file, folder, flags);
	free_list(&file);
}

void	ls_dir(t_dirs **folder, int flags)
{
	DIR		*dr;

	while (*folder)
	{
		dr = opendir((*folder)->dirname);
		if (errno == 0)
		{
			ls_print((*folder)->dirname, flags);
			closedir(dr);
		}
		else if (errno == 20)
			ls_print((*folder)->dirname, flags);
		else if (errno == 13)
			invalid_perm((*folder)->dirname);
		else if (errno == 2)
			invalid_folder((*folder)->dirname);
		*folder = (*folder)->next;
	}
}

t_dirs	*ls_arg(int ac, char **av, t_dirs **dirs, int *flags)
{
	int		i = 1;
	
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			av[i]++;
			ls_flags(flags, av[i]);
		}
		else
			*dirs = add_dir(av[i], *dirs);
		i++;
	}
	return (*dirs);
}