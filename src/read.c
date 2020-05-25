#include "ft_ls.h"

static void		read_folder(t_file **file, DIR *dr, char *folder, int flags)
{
	char			*drpath;
	struct dirent	*de;
	struct stat		stats;

	while ((de = readdir(dr)))
	{
		path(folder, de->d_name, &drpath);
		stat(drpath, &stats);
		ft_strdel(&drpath);
		if (!(flags & LS_A) && de->d_name[0] == '.')
			continue;
		else
			*file = add_file(*file, de->d_name, stats);
	}
}

void			build_path(t_file **file, char *folder, int flags)
{
	DIR				*dr;
	struct stat		stats;

	dr = opendir(folder);
	if (errno == 20)
	{
		stat(folder, &stats);
		*file = add_file(*file, folder, stats);
	}
	else if (errno == 2)
		invalid_folder(folder);
	else if (errno == 13)
		invalid_perm(folder);
	else
	{
		read_folder(file, dr, folder, flags);
		closedir(dr);
	}
}