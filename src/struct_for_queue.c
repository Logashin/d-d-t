/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_for_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:52:32 by tmann             #+#    #+#             */
/*   Updated: 2019/06/01 15:45:34 by tmann            ###   ########.fr       */
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
