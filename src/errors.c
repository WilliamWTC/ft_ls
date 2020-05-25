#include "ft_ls.h"

void	invalid_flag(char *str)
{
	ft_putstr("ft_ls: invalid option -- '");
	ft_putchar(str[0]);
	ft_putstr("'\nft_ls options are: [-aRrt] [path...]\n");
	exit(0);
}

void	invalid_folder(char *str)
{
	ft_putstr("ft_ls: cannot access '");
	ft_putstr(str);
	ft_putendl("' : No such file or directory");
	errno = 0;
}

void	invalid_perm(char *str)
{
	ft_putstr("Permission denied for : ");
	ft_putendl(str);
	errno = 0;
}