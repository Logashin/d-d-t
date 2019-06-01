/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:11:04 by tmann             #+#    #+#             */
/*   Updated: 2019/06/01 15:12:50 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_visited(t_lst *lst)
{
	while (lst)
	{
		lst->visited = 0;
		lst = lst->next;
	}
}

void		func_kill_cross(t_lst *lst)
{
	while (lst->end != 1)
	{
		if (lst->start == 1)
			lst = lst->next;
		if (lst->end == 0)
			kill_cross(lst);
		lst = lst->next;
	}
}

void		c_par_out(t_lst *lst, t_lem *po)
{
	while (lst)
	{
		lst->visited = 0;
		if (lst->start == 1)
		{
			po->size_con_start = lst->sizeconn;
			lst = lst->next;
		}
		if (lst->end == 1)
			po->size_con_end = lst->sizeconn;
		create_par(lst);
		create_output(lst);
		lst = lst->next;
	}
}

int			main(void)
{
	t_lem	*po;
	t_lst	*lst;
	t_lst	*hl;

	po = NULL;
	lst = creat_list();
	po = scan_param(po, lst);
	lst = ft_sort_list(lst);
	ft_bfs(lst, po);
	hl = lst;
	lst = hl;
	c_par_out(lst, po);
	func_kill_cross(lst);
	free_visited(lst);
	ft_bfs(lst, po);
	ants_go_output(po, lst, 1, lst);
	return (0);
}
