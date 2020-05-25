#include "ft_ls.h"

int			main(int ac, char **av)
{
	t_dirs	*dirs;
	int		flags = 0;

	dirs = NULL;
	dirs = ls_arg(ac, av, &dirs, &flags);
	if (dirs != NULL)
		ls_dir(&dirs, flags);
	else
		ls_print(".", flags);
	free_dir(&dirs);
	return (0);
}