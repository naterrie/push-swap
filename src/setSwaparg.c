/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setSwaparg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:37:21 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/22 17:48:55 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../SwapPush.h"

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
		swap->a[k] = (swap->a[k] * 10) + (str[j++] - '0');
	if (neg == 1)
		swap->a[k] *= -1;
	return (0);
}

int	ft_tabatoi(char **args, t_push *swap)
{
	char	*temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	temp = malloc(sizeof(char) * 6);
	while (args[1][i])
	{
		if (args[1][i] == ' ')
		{
			if (args[1][i + 1] != ' ')
			{
				j++;
				ft_atoi(temp, swap, j);
				k = 0;
			}
			i++;
			if (temp[6] != '\0')
			{
				write(1, "ERROR\n", 6);
				return (free (temp), 1);
			}
		}
		temp[k] = args[1][i];
		i++;
		k++;
	}
	return (free (temp), 0);
}

static int	check_other_char(char **args)
{
	int	i;

	i = 0;
	while (args[1][i])
	{
		if ((args[1][i] < '0' || args[1][i] > '9') && \
				args[1][i] != '-' && args[1][i] != ' ')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

void	sizetomalloc(char **args, t_push *push)
{
	int	i;

	i = 0;
	while (args[1][i])
	{
		while (args[1][i] == ' ' || args[1][i] == '-' || args[1][i] == '+')
			i++;
		while (args[1][i] >= '0' && args[1][i] <= '9')
			i++;
		push->lena++;
	}
	push->a = malloc(sizeof(int) * push->lena);
	if (!push->a)
		return ;
	push->b = malloc(sizeof(int) * push->lena);
	if (!push->b)
		return ;
}

int	set_pushwap_arg(char **args, t_push *push)
{
	if (check_other_char(args))
		return (1);
	sizetomalloc(args, push);
	if (ft_tabatoi(args, push) == 1)
		return (1);
	if (checksame(push) == 1)
		return (1);
	return (0);
}