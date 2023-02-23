/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SwapPush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:52:43 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/23 14:13:25 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../SwapPush.h"

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
				write(1, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	printcolonne(t_push *swap)
{
	int	i;

	i = -1;
	while (++i < swap->lena)
	{
		printf("%d=%d\n", i, swap->a[i]);
	}
	printf("len a = %d\n", swap->lena);
	i = -1;
	while (++i < swap->lenb)
	{
		printf("%d=%d\n", i, swap->b[i]);
	}
	printf("len b = %d\n", swap->lenb);
}

int	main(int argc, char **argv)
{
	t_push	push;

	push.lena = 0;
	push.lenb = 0;
	if (argc == 1)
	{
		write(1, "Error\n", 6);
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
	printcolonne(&push);
	sort(&push);
	return (free (push.a), free (push.b), 0);
}
