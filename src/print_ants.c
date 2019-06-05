/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:43:16 by tmann             #+#    #+#             */
/*   Updated: 2019/06/05 15:08:28 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			use_ways(t_lem *po)
{
	int i;
	int p;

	i = 0;
	p = 0;
	while (po->ways[i])
	{
		if (po->ways[i]->green > 0)
			p++;
		i++;
	}
	return (p);
}

void				create_ants_here(t_lem *po, int j, int i, int p)
{
	p = use_ways(po);
	while (1)
	{
		j = 0;
		while (j < po->num_ants)
		{
			if (i == p)
			{
				i = 0;
				break ;
			}
			if (po->here[j] == NULL && j < po->run_num_ants)
			{
				j++;
				continue ;
			}
			if (po->here[j] == NULL)
			{
				if (po->ways[i]->green > 0)
				{
					po->here[j] = po->ways[i];
					po->ways[i]->green--;
					po->run_num_ants++;
				}
				if (po->count_way > i)
					i++;
			}
			else
				po->here[j] = po->here[j]->go;
			if (po->here[j] != NULL)
				ft_printf("L%d-%s ", j + 1, po->here[j]->name_s);
			if (po->here[j] != NULL && po->here[j]->end == 1)
			{
				po->here[j] = NULL;
			}

			j++;
		}
		ft_printf("\n");
		if (is_all_ants_in_end(po) == 0)
			break ;
		else
			i = 0;
	}
}
