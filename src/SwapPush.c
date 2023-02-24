/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SwapPush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:52:43 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/24 16:31:18 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../SwapPush.h"

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
				write(STDERR_FILENO, "Error\n", 6);
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
	{
		write(1, "\n", 1);
		return (0);
	}
	else if (argc == 2)
	{
		if (set_pushwap_arg(argv, &push) == 1)
			return (0);
	}
	else
	{
		if (set_pushwap_args(argv, &push) == 1)
			return (0);
	}
	sort(&push);
	free (push.a);
	free (push.b);
	return (0);
}
