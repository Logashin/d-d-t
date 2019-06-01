/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_accuracy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:33:36 by tmann             #+#    #+#             */
/*   Updated: 2019/03/25 16:17:27 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*print_drobnoe(int nbr, long double drobnoe, int **sim)
{
	char	*str;
	int		i;
	int		tmp;

	i = 0;
	str = (char*)malloc(sizeof(char) * nbr + 1);
	if (!str)
		return (NULL);
	while (i < nbr)
	{
		drobnoe *= 10;
		tmp = drobnoe;
		str[i] = (unsigned long long)drobnoe + '0';
		drobnoe -= tmp;
		i++;
	}
	(*sim)[0] = drobnoe * 10;
	str[i] = '\0';
	return (str);
}

char		*ft_float_ac_0(long double nbr, int *sim)
{
	char				*drobstr;
	long long			celoe;
	double				drobnoe;

	celoe = nbr;
	drobnoe = nbr - celoe;
	if (drobnoe < 0)
		drobnoe *= -1;
	drobstr = print_drobnoe(6, drobnoe, &sim);
	return (drobstr);
}

char		*ft_float_ac_big(t_print *po, long double nbr, int *sim)
{
	char				*drobstr;
	long long			celoe;
	double				drobnoe;

	celoe = nbr;
	drobnoe = nbr - celoe;
	if (drobnoe < 0)
		drobnoe *= -1;
	drobstr = print_drobnoe(po->accuracy, drobnoe, &sim);
	return (drobstr);
}

void		ft_float_ac_minus(t_print *po, char *celstr)
{
	if (po->sharp == 1 && po->minus == 0)
		po->width--;
	else if (po->sharp == 1 && po->accuracy == -1)
		po->width--;
	ft_space_string_dec(celstr, po, 0);
	if (po->sharp == 1 && po->minus == 0)
		ft_putchar('.');
	else if (po->sharp == 1 && po->accuracy == -1)
		ft_putchar('.');
}
