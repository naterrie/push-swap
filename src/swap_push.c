/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:52:43 by naterrie          #+#    #+#             */
/*   Updated: 2023/04/20 14:19:54 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../swap_push.h"

void	ft_exit(t_push *swap)
{
	free(swap->a);
	free(swap->b);
	exit(1);
}

void	sort_four(t_push *swap)
{
	if (sort_check(swap) == 1)
	{
		while (swap->lena != 3)
		{
			if (swap->a[0] == 0)
				pb(swap);
			rra(swap);
		}
		sort_three(swap);
		pa(swap);
		if (swap->a[0] > swap->a[1])
			sa(swap);
	}
}

int	sort_check(t_push *swap)
{
	int	i;

	i = 0;
	while (i < swap->lena - 1)
	{
		if (swap->a[i] > swap->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	checksame(t_push *swap)
{
	int	i;
	int	j;

	i = 0;
	while (i < swap->lena)
	{
		j = 0;
		while (j < swap->lena)
		{
			if (swap->a[i] == swap->a[j] && i != j)
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

int	main(int argc, char **argv)
{
	t_push	push;

	push.lena = 0;
	push.lenb = 0;
	if (write (1, "", 0) == -1)
		return (0);
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (set_pushwap_arg(argv, &push) == 1)
			return (1);
	}
	else
	{
		if (set_multiple_args(argv, &push) == 1)
			return (1);
	}
	sort(&push);
	free (push.a);
	free (push.b);
	return (0);
}

