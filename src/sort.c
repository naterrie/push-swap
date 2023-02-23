/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:16:12 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/23 14:31:30 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../SwapPush.h"

int	*ft_index(t_push *swap)
{
	int	*temp;
	int	i;
	int	j;
	int	k;

	i = 0;
	temp = malloc(sizeof(int) * swap->lena);
	while (i < swap->lena)
	{
		j = 0;
		k = 0;
		while (j < swap->lena)
		{
			if (swap->a[j] < swap->a[i])
				k++;
			j++;
		}
		temp[i] = k;
		i++;
	}
	return (free(swap->a), temp);
}

void	sort_three(t_push *swap)
{
	if (swap->a[0] > swap->a[1] && swap->a[0] < swap->a[2] \
								&& swap->a[1] < swap->a[2])
		sa(swap);
	if (swap->a[0] > swap->a[2] && swap->a[0] < swap->a[1])
		rra(swap);
	if (swap->a[0] > swap->a[1] && swap->a[2] < swap->a[0])
		ra(swap);
	if (swap->a[0] > swap->a[1])
		sa(swap);
	if (swap->a[0] < swap->a[1] && swap->a[1] > swap->a[2])
	{
		rra(swap);
		sa(swap);
	}
}

void	sort(t_push *swap)
{
	swap->a = ft_index(swap);
	printcolonne(swap);
	if (swap->lena == 3)
	{
		sort_three(swap);
		return ;
	}
}
