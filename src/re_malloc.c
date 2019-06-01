/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:24:18 by tmann             #+#    #+#             */
/*   Updated: 2019/05/31 15:26:26 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lst		*creat_list(void)
{
	t_lst *lst;

	lst = (t_lst*)malloc(sizeof(t_lst));
	ft_lst_zero(lst);
	return (lst);
}

void		re_write(t_lst *lst)
{
	t_lst	**new;
	int		i;

	i = 0;
	new = (t_lst**)malloc(sizeof(t_lst*) * (lst->sizeconn + 1));
	while (i < lst->sizeconn)
	{
		new[i] = (t_lst*)malloc(sizeof(t_lst));
		new[i] = lst->conn[i];
		i++;
	}
	new[i] = NULL;
	free(lst->conn);
	lst->conn = NULL;
	lst->conn = new;
}

void		try_write_par(t_lst *lst)
{
	t_lst	**new;
	int		i;

	i = 1;
	lst->sizepar++;
	new = (t_lst**)malloc(sizeof(t_lst) * (lst->sizepar));
	new[0] = NULL;
	while (i < lst->sizepar)
	{
		new[i] = (t_lst*)malloc(sizeof(t_lst));
		new[i] = lst->par[i - 1];
		i++;
	}
	free(lst->par);
	lst->par = NULL;
	lst->par = new;
}

void		re_output(t_lst *lst)
{
	t_lst	**new;
	int		i;

	i = 1;
	lst->sizeoutput++;
	new = (t_lst **)malloc(sizeof(t_lst *) * (lst->sizeoutput));
	new[0] = NULL;
	while (i < lst->sizeoutput)
	{
		new[i] = (t_lst *)malloc(sizeof(t_lst));
		new[i] = lst->output[i - 1];
		i++;
	}
	lst->output = NULL;
	lst->output = new;
}
