/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:43:27 by tmann             #+#    #+#             */
/*   Updated: 2019/03/16 18:52:21 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(long long int nbr, long long int base)
{
	int i;

	i = 0;
	if (nbr < 0 || nbr == 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char		*ft_ltoa_base(long long int nbr, int base)
{
	char			*str;
	long long int	len;

	if (nbr < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	len = nbrlen(nbr, base);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		if (nbr % base < 10)
			str[--len] = nbr % base + '0';
		else
			str[--len] = nbr % base + 'A' - 10;
		nbr /= base;
	}
	return (str);
}
