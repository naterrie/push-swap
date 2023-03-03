/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkminus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:06:59 by naterrie          #+#    #+#             */
/*   Updated: 2023/03/03 16:47:12 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../SwapPush.h"

int	check_minusargs(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if ((args[i][j] == '+' || args[i][j] == '-') && \
				(args[i][j + 1] < '0' || args[i][j + 1] > '9'))
			{
				write (2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_minusarg(char **args)
{
	int	j;

	j = 0;
	while (args[1][j])
	{
		if ((args[1][j] == '+' || args[1][j] == '-') && \
			(args[1][j + 1] < '0' || args[1][j + 1] > '9'))
		{
			write (2, "Error\n", 6);
			return (1);
		}
		j++;
	}
	return (0);
}
