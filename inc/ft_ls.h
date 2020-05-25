#ifndef FT_LS_H
# define FT_LS_H

# define LS_A	1
# define LS_RR	2
# define LS_R	4
# define LS_T	8

# include "libft.h"
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/types.h>

typedef	struct		s_file
{
	char			*name;
	char			*d;
	time_t			time;
	struct s_file	*next;
}					t_file;

typedef	struct		s_dirs
{
	char			*dirname;
	struct s_dirs	*next;
}					t_dirs;

t_file				*add_file();
t_dirs				*add_dir();
t_file				*new_file();
t_dirs				*new_dir();

void				free_list();
void				free_dir();

void				split_list();
void				sort_list();
t_file				*by_ascii();
t_file				*by_time();

t_dirs				*ls_arg();
void				ls_dir();
void				ls_print();

void				build_path();
void				ls_flags();
void				print_file();

char 				filetype();
char 				*rec_att();

int 				can_recurse();
void				ls_recur();
void				free_rec();

void				invalid_flag();
void				invalid_folder();
void				invalid_perm();
void				dir_errors();

void				ft_ls();

#endif