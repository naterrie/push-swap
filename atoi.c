/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:33:07 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/15 13:33:37 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	sign(int nb)
{
	if (nb == -1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str, int i)
{
	long	i;
	int		neg;

	j = 0;
	i = 0;
	neg = -1;
	if (str[j] != '\0' && str[j] == '-')
	{
		neg *= -1;
		j++;
	}
	else if (str[j] == '+')
		i++;
	while (ft_isdigit(str[j]))
	{
		if (str[j] < '0' || str[j] > '9')
			return (1);
		if (i != ((i * 10) + (str[j] - '0')) / 10)
			return (sign(neg));
		i = (i * 10) + (str[j++] - '0');
	}
	if (neg == 1)
		i = -i;
	return (0);
}

int	ft_tabatoi(char **args, int *i)
{
	int j;

	j = 1;
	while (args[j])
	{
		if (ft_atoi(args[j], i[j-1]) == 1)
			return (1);
		j++;
	}
	return (0);
}