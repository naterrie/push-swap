/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SwapPush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:52:43 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/21 18:58:04 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../SwapPush.h"

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

int	checksame(t_push *swap)
{
	int	i;
	int	j;

	i = 0;
	while (i <= swap->lena)
	{
		j = 0;
		while (j <= swap->lena)
		{
			if (swap->a[i] == swap->a[j] && i != j)
			{
				write(1, "ERROR\nSame character are not allowed !\n", 39);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	set_pushwap(char **args, t_push *push)
{
	push->lena = 0;
	while (args[push->lena])
		push->lena++;
	push->lena -= 1;
	push->lenb = 0;
	push->a = malloc(sizeof(int) * (push->lena));
	if (!push->a)
		return (1);
	push->b = malloc(sizeof(int) * (push->lena));
	if (!push->b)
		return (free (push->a), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_push	push;

	if (argc == 1 || argc == 2)
	{
		write(1, "ERROR\nEnter At least two numbers!\n", 34);
		return (0);
	}
	if (set_pushwap(argv, &push) == 1)
		return (0);
	if (ft_tabatoi(argv, &push) == 1)
		return (0);
	if (checksame(&push) == 1)
		return (0);
	rrr(&push);
	printcolonne(&push);
}
