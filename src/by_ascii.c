# include "ft_ls.h"

t_file		*by_ascii(t_file *left, t_file *right, int flags)
{
	t_file *res;

	res = NULL;
	if (!left)
		return (right);
	if (!right)
		return (left);
	if (!(flags & LS_R) && (ft_strcmp(left->name, right->name)) < 0)
	{
		res = left;
		res->next = by_ascii(left->next, right, flags);
	}
	else if ((flags & LS_R) && (ft_strcmp(left->name, right->name)) > 0)
	{
	 	res = left;
	 	res->next = by_ascii(left->next, right, flags);
	}
	else
	{
		res = right;
		res->next = by_ascii(left, right->next, flags);
	}
	return (res);
}