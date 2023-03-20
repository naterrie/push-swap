/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_multiple_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:37:21 by naterrie          #+#    #+#             */
/*   Updated: 2023/03/20 17:10:29 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../swap_push.h"

static int	ft_atoi(const char *str, t_push *swap, int k)
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
		if (swap->a[k] != ((swap->a[k] * 10) + (str[j] - '0')) / 10)
			return (write(2, "Error\n", 6), 1);
		swap->a[k] = (swap->a[k] * 10) + (str[j++] - '0');
	}
	if (neg == 1)
		swap->a[k] *= -1;
	return (0);
}

static int	ft_tabatoi(char **args, t_push *swap)
{
	char	**temp;
	int		i;

	(void) swap;
	i = 0;
	temp = ft_split(args[1], ' ');
	if (temp == NULL)
		return (1);
	while (temp[i])
	{
		if (ft_atoi(temp[i], swap, i) == 1)
		{
			while (i >= 0)
				free(temp[i--]);
			free(temp);
			return (1);
		}
		i++;
	}
	free_str(temp);
	return (0);
}

static int	check_other_char(char **args)
{
	int	i;

	i = 0;
	while (args[1][i])
	{
		if ((args[1][i] < '0' || args[1][i] > '9') && \
				args[1][i] != '-' && args[1][i] != ' ' \
				&& args[1][i] != '+')
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	sizetomalloc(char **args, t_push *push)
{
	int	i;

	i = 0;
	while (args[1][i])
	{
		while (args[1][i] == ' ' || args[1][i] == '-' || args[1][i] == '+')
			i++;
		while (args[1][i] >= '0' && args[1][i] <= '9')
			i++;
		if (args[1][i + 1])
			push->lena++;
	}
	push->a = malloc(sizeof(int) * push->lena);
	if (!push->a)
		return (1);
	push->b = malloc(sizeof(int) * push->lena);
	if (!push->b)
		return (free(push->a), 1);
	set_to_zero(push);
	return (0);
}

int	set_pushwap_arg(char **args, t_push *push)
{
	if (check_minusarg(args) == 1)
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
