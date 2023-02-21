/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:33:07 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/21 16:00:46 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../SwapPush.h"

int	ft_atoi(const char *str, int *i)
{
	long	j;
	int		neg;

	j = 0;
	neg = -1;
	if (str[j] != '\0' && str[j] == '-')
	{
		neg *= -1;
		j++;
	}
	else if (str[j] == '+')
		j++;
	while (str[j])
	{
		if (str[j] < '0' || str[j] > '9')
			return (write(1, \
			"Error\nOther characters detected !\n", 35), 1);
		if (*i != ((*i * 10) + (str[j] - '0')) / 10)
			return (write(1, \
			"Error\nA number is highter than an int !\n", 40), 1);
		*i = (*i * 10) + (str[j++] - '0');
	}
	if (neg == 1)
		*i *= -1;
	return (0);
}

int	ft_tabatoi(char **args, t_push *swap)
{
	int	j;

	j = 0;
	while (args[++j])
	{
		if (ft_atoi(args[j], &swap->a[j - 1]) == 1)
			return (1);
	}
	return (0);
}
