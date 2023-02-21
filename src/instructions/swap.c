/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:49:15 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/21 13:55:48 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

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

void	sb(t_push *swap)
{
	int	temp;

	if (swap->lenb == 0 || swap->lenb == 1)
		return ;
	temp = swap->b[0];
	swap->b[0] = swap->b[1];
	swap->b[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_push *swap)
{
	int	temp;

	if (swap->lenb > 2)
	{
		temp = swap->b[0];
		swap->b[0] = swap->b[1];
		swap->b[1] = temp;
	}
	if (swap->lena > 2)
	{
		temp = swap->a[0];
		swap->a[0] = swap->a[1];
		swap->a[1] = temp;
	}
	write(1, "ss\n", 3);
}
