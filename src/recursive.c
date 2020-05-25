#include "ft_ls.h"

void	ls_recur(t_file **head, char *s2, int flags)
{
	t_file		*file;
	char		*s1;
	char		*path;

	file = *head;
	while (file)
	{
		if (can_recurse(file))
		{
			s1 = ft_strjoin(s2, "/");
			path = ft_strjoin(s1, file->name);
			ft_putchar('\n');
			rec_path(path);
			ls_print(path, flags);
			free_rec(s1, path);
		}
		file = file->next;
	}
}