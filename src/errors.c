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
	ft_putstr("' : No such file or directory");
	ft_putstr("\n");
	errno = 0;
}

void	invalid_perm(char *str)
{
	ft_putstr("Permission denied for : ");
	ft_putstr(str);
	ft_putchar('\n');
	errno = 0;
}