/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:52:15 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/21 15:49:32 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

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
}
