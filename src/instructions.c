/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:55:25 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/24 14:40:29 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../SwapPush.h"

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

void	sa(t_push *swap)
{
	int	temp;

	if (swap->lena == 0 || swap->lena == 1)
		return ;
	temp = swap->a[0];
	swap->a[0] = swap->a[1];
	swap->a[1] = temp;
	write(1, "sa\n", 3);
}

void	pa(t_push *swap)
{
	int	size;

	if (swap->lenb == 0)
		return ;
	size = swap->lena;
	while (size > 0)
	{
		swap->a[size] = swap->a[size - 1];
		size--;
	}
	swap->a[0] = swap->b[0];
	swap->lena += 1;
	size = 0;
	while (size < swap->lenb)
	{
		swap->b[size] = swap->b[size + 1];
		size++;
	}
	swap->lenb -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_push *swap)
{
	int	size;

	size = 0;
	if (swap->lena == 0)
		return ;
	size = swap->lenb;
	while (size > 0)
	{
		swap->b[size] = swap->b[size - 1];
		size--;
	}
	swap->b[0] = swap->a[0];
	swap->lenb += 1;
	size = 0;
	while (size < swap->lena)
	{
		swap->a[size] = swap->a[size + 1];
		size++;
	}
	swap->lena -= 1;
	write(1, "pb\n", 3);
}
