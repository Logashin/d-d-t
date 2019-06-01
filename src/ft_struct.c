/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:54:28 by tmann             #+#    #+#             */
/*   Updated: 2019/05/31 21:43:12 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_struct_zero(t_lem *po)
{
	po->num_ants = 0;
	po->line = 0;
	po->check_start = 0;
	po->check_end = 0;
	po->command = NULL;
	po->val_end = 0;
	po->val_start = 0;
	po->ways = NULL;
	po->min_way = 2147483647;
	po->bfs_count = 0;
	po->val_start = 0;
	po->size_con_end = 0;
}

void		ft_lst_zero(t_lst *lst)
{
	lst->name_s = NULL;
	lst->corname_x = -1;
	lst->corname_y = -1;
	lst->ant = 0;
	lst->conn = NULL;
	lst->start = 0;
	lst->end = 0;
	lst->next = NULL;
	lst->parent = NULL;
	lst->sizeconn = 0;
	lst->is_first = 0;
	lst->visited = 0;
	lst->green = 0;
	lst->sizepar = 0;
	lst->par = NULL;
	lst->ok = 0;
	lst->go = NULL;
	lst->bfs_lvl = -1;
	lst->output = NULL;
	lst->sizeoutput = 0;
	lst->quick = NULL;
	lst->dead_end = 0;
	lst->alone = 0;
	lst->len_way = -1;
	lst->i = -1;
}
