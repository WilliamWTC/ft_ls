#include "ft_ls.h"

void	print_file(t_file *file)
{
 	while (file)
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
	t_dirs	*direc;

	direc = *folder;
	while (direc)
	{
		dr = opendir(direc->dirname);
		if (errno == 0)
		{
			ls_print(direc->dirname, flags);
			closedir(dr);
		}
		else if (errno == 20)
			ls_print(direc->dirname, flags);
		else 
			dir_errors(errno, direc->dirname);

		direc = direc->next;
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

void		ft_ls(t_dirs *stream, int flags)
{
	if (stream != NULL)
		ls_dir(&stream, flags);
	else
		ls_print(".", flags);
	free_dir(&stream);
}