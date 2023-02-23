/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:24:08 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/23 11:33:27 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../SwapPush.h"

void	rra(t_push *swap)
{
	int	temp;
	int	size;

	temp = swap->a[swap->lena - 1];
	if (swap->lena == 0)
		return ;
	size = swap->lena;
	while (size > 0)
	{
		swap->a[size] = swap->a[size - 1];
		size--;
	}
	swap->a[0] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_push *swap)
{
	int	temp;
	int	size;

	temp = swap->b[swap->lenb - 1];
	if (swap->lenb == 0)
		return ;
	size = swap->lenb;
	while (size > 0)
	{
		swap->b[size] = swap->b[size - 1];
		size--;
	}
	swap->b[0] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_push *swap)
{
	int	temp;
	int	size;

	if (swap->lena != 0)
	{
		temp = swap->a[swap->lena - 1];
		size = swap->lena;
		while (--size > 0)
			swap->a[size] = swap->a[size - 1];
		swap->a[0] = temp;
	}
	if (swap->lenb != 0)
	{
		temp = swap->b[swap->lenb - 1];
		size = swap->lenb;
		while (size > 0)
		{
			swap->b[size] = swap->b[size - 1];
			size--;
		}
		swap->b[0] = temp;
	}
	write(1, "rrr\n", 4);
}
