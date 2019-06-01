/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_val_p2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:32:16 by tmann             #+#    #+#             */
/*   Updated: 2019/04/22 19:03:02 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_double_param(t_lst *lst, char *str)
{
	t_lst	*tmp;
	char	**param;

	tmp = lst;
	param = ft_strsplit(str, ' ');
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->name_s, param[0]) == 0)
			ft_error_ps();
		if (tmp->corname_x == ft_swap_atoi(param[1])
			&& tmp->corname_y == ft_swap_atoi(param[2]))
			ft_error_ps();
		tmp = tmp->next;
	}
	ft_free_two_arr(param);
}
