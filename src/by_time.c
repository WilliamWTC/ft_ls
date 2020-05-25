#include "ft_ls.h"

t_file		*by_time(t_file *a, t_file *b, int flags)
{
	t_file *res;

	res = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if ((a->time > b->time) && !(flags & LS_R))
	{
		res = a;
		res->next = by_time(a->next, b, flags);
	}
	else if ((a->time < b->time) && (flags & LS_R))
	{
	 	res = a;
	 	res->next = by_time(a->next, b, flags);
	}
	else
	{
		res = b;
		res->next = by_time(a, b->next, flags);
	}
	return (res);
}