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