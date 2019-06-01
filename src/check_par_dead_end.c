/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_par_dead_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:26:00 by tmann             #+#    #+#             */
/*   Updated: 2019/05/31 21:49:05 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			return_check(t_lst *lst, int dead_and, int o_p, int res)
{
	if (dead_and == 1 && o_p == 1)
		lst->alone = 1;
	if (lst->dead_end == -1)
		return (0);
	if (lst->sizeoutput > res)
		return (1);
	else
		return (0);
}

int					var_param(int *dead_and, int *o_p, t_lst *lst, t_lst *par)
{
	if (lst->output[lst->i]->dead_end == -1)
		(*dead_and)++;
	else if (ft_strcmp(lst->output[lst->i]->name_s, par->name_s) == 0)
		(*o_p)++;
	return (1);
}

int					check_par_dead_end(t_lst *lst, t_lst *par, int i, int res)
{
	int dead_and;
	int o_p;

	dead_and = 0;
	o_p = 0;
	i = 0;
	while (lst->sizeoutput > ++lst->i)
	{
		if (ft_strcmp(lst->output[lst->i]->name_s, lst->name_s) == 0)
			res++;
		else if ((lst->output[lst->i]->dead_end == -1) ||
		(ft_strcmp(lst->output[lst->i]->name_s, par->name_s) == 0))
			res += var_param(&dead_and, &o_p, lst, par);
		else if (lst->output[lst->i]->sizeoutput == 1 && o_p == 1)
			lst->alone = 1;
		else if (lst->output[lst->i]->end == 1)
			res++;
		else if ((check_double_op(lst) == 0) ||
			(lst->sizeoutput == 1 && lst->sizepar == 2))
			return (0);
	}
	return (return_check(lst, dead_and, o_p, res));
}
