#include "ft_ls.h"

int			main(int ac, char **av)
{
	t_dirs	*dirs;
	int		flags = 0;

	dirs = NULL;
	dirs = ls_arg(ac, av, &dirs, &flags);
	ft_ls(dirs, flags);

	return (0);
}