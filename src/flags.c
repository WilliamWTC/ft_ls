#include "ft_ls.h"

void	ls_flags(char *str, int *flags)
{
	while (*str != '\0')
	{
		if (ft_strchr("aRrt", *str))
		{
			if (*str == 'a')
				*flags |= LS_A;
			if (*str == 'R')
				*flags |= LS_RR;
			if (*str == 'r')
				*flags |= LS_R;
			if (*str == 't')
				*flags |= LS_T;
			str++;
		}
		else
			invalid_flag(str);
	}
}
