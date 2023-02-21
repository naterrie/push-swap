/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:55:25 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/21 18:52:54 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../SwapPush.h"

void	ra(t_push *swap)
{
	int	size;
	int	temp;

	if (swap->lena == 0)
		return ;
	temp = swap->a[0];
	size = 0;
	while (size < swap->lena)
	{
		swap->a[size] = swap->a[size + 1];
		size++;
	}
	swap->a[swap->lena - 1] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_push *swap)
{
	int	size;
	int	temp;

	if (swap->lenb == 0)
		return ;
	temp = swap->b[0];
	size = 0;
	while (size < swap->lenb)
	{
		swap->b[size] = swap->b[size + 1];
		size++;
	}
	swap->b[swap->lenb - 1] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_push *swap)
{
	int	size;
	int	temp;

	if (swap->lena != 0)
	{
		temp = swap->a[0];
		size = -1;
		while (++size < swap->lena)
			swap->a[size] = swap->a[size + 1];
		swap->a[swap->lena - 1] = temp;
	}
	if (swap->lenb != 0)
	{
		temp = swap->b[0];
		size = 0;
		while (size < swap->lenb)
		{
			swap->b[size] = swap->b[size + 1];
			size++;
		}
		swap->b[swap->lenb - 1] = temp;
	}
	write(1, "rr\n", 3);
}
