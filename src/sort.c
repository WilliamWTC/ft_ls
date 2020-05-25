#include "ft_ls.h"

void		split_list(t_file *tmp, t_file **a, t_file **b)
{
	t_file	*left;
	t_file	*right;

	if (!tmp || !tmp->next)
	{
		*a = tmp;
		*b = NULL;
	}
	else
	{
		left = tmp;
		right = tmp->next;
		while (right)
		{
			right = right->next;
			if (right)
			{
				right = right->next;
				left = left->next;
			}
		}
		*a = tmp;
		*b = left->next;
		left->next = NULL;
	}
}

void		sort_list(t_file **head, int flags)
{
	t_file	*tmp;
	t_file	*left;
	t_file	*right;

	tmp = *head;
	if (tmp && tmp->next)
	{
		split_list(tmp, &left, &right);
		sort_list(&left, flags);
		sort_list(&right, flags);
		if (flags & LS_T)
			*head = by_time(left, right, flags);
		else
			*head = by_ascii(left, right, flags);
	}
}