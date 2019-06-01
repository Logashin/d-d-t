/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_of_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:00:41 by dspider-          #+#    #+#             */
/*   Updated: 2019/05/31 22:06:55 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		vitya_create_name2(t_lst *lst, int *left, int *k)
{
	(*left)--;
	lst->ant++;
	lst->visited++;
	lst->green = *k;
	(*k)++;
	ft_printf("L%d-%s ", lst->green, lst->name_s);
}

void		vitya_create_name(t_lst *lst)
{
	if (lst->ant > 0 && lst->visited > 0)
	{
		lst->go->red = lst->green;
		lst->go->ant++;
		lst->ant--;
		ft_printf("L%d-%s ", lst->green, lst->go->name_s);
		lst->green = lst->red;
	}
	else if (lst->ant > 0 && lst->visited == 0)
	{
		if (lst->green == 0)
			lst->green = lst->red;
		lst->visited++;
	}
}

void		ants_go_output(t_lem *po, t_lst *hl, int i, t_lst *end)
{
	t_lst	*lst;
	int		left;
	int		k;

	while (end->end != 1)
	{
		end->red = 0;
		end = end->next;
	}
	left = po->num_ants;
	k = 1;
	while (po->num_ants != end->ant)
	{
		i = 0;
		while (i < hl->sizeconn)
		{
			lst = hl->conn[i];
			while (lst->go != NULL)
			{
				vitya_create_name(lst);
				lst = lst->go;
			}
			lst = hl->conn[i];
			if (lst->go != NULL && left > 0)
				vitya_create_name2(lst, &left, &k);
			i++;
		}
		ft_printf("\n");
	}
}
