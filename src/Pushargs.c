/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pushargs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:27:58 by naterrie          #+#    #+#             */
/*   Updated: 2023/03/10 17:27:47 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../SwapPush.h"

static int	ft_atoi(const char *str, int *i)
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
		if (*i != ((*i * 10) + (str[j] - '0')) / 10)
			return (write(2, "Error\n", 6), 1);
		*i = (*i * 10) + (str[j++] - '0');
	}
	if (neg == 1)
		*i *= -1;
	return (0);
}

static int	ft_tabatoi(char **args, t_push *swap)
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

static int	check_other_char(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if ((args[i][j] < '0' || args[i][j] > '9') && \
				args[i][j] != '-' && args[i][j] != '+'
				)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	sizetomalloc(char **args, t_push *push)
{
	while (args[++push->lena])
		;
	push->lena--;
	push->a = malloc(sizeof(int) * push->lena);
	if (!push->a)
		return (1);
	push->b = malloc(sizeof(int) * push->lena);
	if (!push->b)
		return (free(push->a), 1);
	set_to_zero(push);
	return (0);
}

int	set_pushwap_args(char **args, t_push *push)
{
	if (check_minusargs(args) == 1)
		return (1);
	if (check_other_char(args))
		return (1);
	if (sizetomalloc(args, push) == 1)
		return (1);
	if (ft_tabatoi(args, push) == 1)
		return (free(push->a), free(push->b), 1);
	if (checksame(push) == 1)
		return (free(push->a), free(push->b), 1);
	return (0);
}
