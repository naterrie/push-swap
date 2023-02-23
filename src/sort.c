/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:16:12 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/23 13:20:48 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../SwapPush.h"

void	sort_three(t_push *swap)
{
	if (swap->a[0] > swap->a[1] && swap->a[1] > swap->a[2])
	{
		pb(swap);
		sa(swap);
		pa(swap);
		rra(swap);
	}
	if (swap->a[0] > swap->a[1] && swap->a[0] < swap->a[2] \
								&& swap->a[1] < swap->a[2])
		sa(swap);
	if (swap->a[0] > swap->a[2] && swap->a[0] < swap->a[1])
		rra(swap);
	if (swap->a[0] > swap->a[1] && swap->a[2] < swap->a[0])
		ra(swap);
	if (swap->a[0] < swap->a[1] && swap->a[1] > swap->a[2])
	{
		pb(swap);
		sa(swap);
		pa(swap);
	}
}

void	sort(t_push *swap)
{
	if (swap->lena == 3)
	{
		sort_three(swap);
		return ;
	}
}
