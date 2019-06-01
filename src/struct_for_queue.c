/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_for_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:52:32 by tmann             #+#    #+#             */
/*   Updated: 2019/05/03 13:36:54 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_zero_queue(t_queue *qu)
{
	qu->name = NULL;
	qu->next = NULL;
}

void		*creat_queue(void)
{
	t_queue	*qu;

	qu = (t_queue*)malloc(sizeof(t_queue));
	qu->name = (t_lst*)malloc(sizeof(t_lst));
	ft_zero_queue(qu);
	return (qu);
}

void		ft_zero_way(t_way *w)
{
	w->name = NULL;
	w->next = NULL;
	w->back = NULL;
	w->size = 0;
}

void		*creat_way(void)
{
	t_way	*w;

	w = (t_way*)malloc(sizeof(t_way));
	w->name = (t_lst*)malloc(sizeof(t_lst));
	ft_zero_way(w);
	return (w);
}

void		*creat_road(void)
{
	t_road	*r;

	r = ft_memalloc(0);
	return (r);
}
