/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:10:53 by tmann             #+#    #+#             */
/*   Updated: 2019/05/31 22:06:05 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef struct		s_lem
{
	int				num_ants;
	int				line;
	int				check_start;
	int				check_end;
	int				val_start;
	int				val_end;
	char			*command;
	struct s_way	*ways;
	int				min_way;
	int				bfs_count;
	int				size_con_end;
	int				size_con_start;
}					t_lem;

typedef struct		s_lst
{
	int				ant;
	int				green;
	int				is_first;
	char			*name_s;
	int				corname_x;
	int				corname_y;
	int				visited;
	int				start;
	int				end;
	int				sizeconn;
	struct s_lst	*parent;
	struct s_lst	**conn;
	struct s_lst	*next;

	struct s_lst	**par;
	int				sizepar;
	int				ok;
	struct s_lst	*go;
	struct s_lst	*quick;

	int				bfs_lvl;
	int				dead_end;

	struct s_lst	**output;
	int				sizeoutput;
	int				alone;
	int				len_way;

	int				red;
	int				i;
}					t_lst;

typedef	struct		s_queue
{
	struct s_lst	*name;
	struct s_queue	*next;
}					t_queue;

typedef	struct		s_way
{
	int				size;
	struct s_lst	*forward;
	struct s_lst	*name;
	struct s_way	*next;
	struct s_way	*back;
}					t_way;

typedef	struct		s_road
{
	struct s_lst	*name;
	struct s_road	*next;
}					t_road;

t_lem				*scan_param(t_lem *po, t_lst *lst);
void				ft_struct_zero(t_lem *po);
void				ft_lst_zero(t_lst *lst);
t_lst				*creat_list(void);
void				readparam(char *line, t_lem *po, t_lst *lst);
void				val_param(char *str, t_lem *po, t_lst *lst, t_lst *head);
void				check_line2(t_lem *po, t_lst *lst, char *str);
void				check_line3(t_lem *po, t_lst *lst, char *str, char **arr);
void				re_write(t_lst *lst);
void				check_double_line_conn(t_lst *lst);
int					count_2d_len(char **arr);
int					count_otr_len(char *str);
void				check_conn(t_lst *lst, t_lst *head);
t_lst				*ft_sort_list(t_lst *lst);
void				check_double_param(t_lst *lst, char *str);

void				*creat_queue(void);
void				ft_zero_queue(t_queue *qu);
t_queue				*ft_add_first_in_queue(t_queue *head,
						t_queue *qu, t_lst *lst);
t_queue				*ft_add_in_queue(t_queue *qu, t_lst *lst);
t_queue				*ft_delete_out_queue(t_queue *qu);

void				ft_bfs(t_lst *lst, t_lem *po);

void				ft_zero_way(t_way *w);
void				*creat_way(void);
void				creat_ways(t_lst *lst, t_lem *po, t_lst *head);
void				creat_quick_way(t_lst *lst);
t_lst				*check_quick(int i, t_lst *tmp);
t_lst				*for_func_quick(int i, t_lst *tmp);
void				del_dead_end(t_lst *lst, int check);

void				*creat_road(void);

void				try_write_par(t_lst *lst);
int					is_or_not(t_lst *lst1, t_lst *lst2);
void				run_ways_from_end(t_lst *lst, t_lem *po,
						int i, int size_way);

void				re_output(t_lst *lst);
void				try_write_par(t_lst *lst);
void				create_par(t_lst *lst);
void				create_output(t_lst *lst);

void				ants_go_output(t_lem *po, t_lst *hl, int i, t_lst *end);

int					check_double_output(t_lst *p, t_lst *lst);
int					check_double_op(t_lst *lst);
int					check_par(t_lst *lst, int i, int check);;
void				del_brother(t_lst *lst, char *brother);
int					check_par_dead_end(t_lst *lst, t_lst *par, int i, int res);
void				kill_cross(t_lst *lst);

#endif
