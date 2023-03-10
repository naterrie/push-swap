/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenumy <adenumy@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:16:12 by naterrie          #+#    #+#             */
/*   Updated: 2023/03/09 11:26:00 by adenumy          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../SwapPush.h"

static int	*ft_index(t_push *swap)
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
		while (j < swap->lena - 1)
		{
			if (swap->a[j] < swap->a[i]) // Et ici aussi au premier passage
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

static void	sort_five(t_push *swap)
{
	if (sort_check(swap) == 1)
	{
		while (swap->lena != 3)
		{
			if (swap->a[0] == 0 || swap->a[0] == 1)
				pb(swap);
			rra(swap);
		}
		sort_three(swap);
		pa(swap);
		pa(swap);
		if (swap->a[0] > swap->a[1])
			sa(swap);
	}
}

void	sort_radix(t_push *swap)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = swap->lena;
	while (sort_check(swap) == 1)
	{
		j = 0;
		while (j < k)
		{
			if (swap->a[0] >> i & 1)
				ra(swap);
			else
				pb(swap);
			j++;
		}
		while (swap->lenb != 0)
			pa(swap);
		i++;
	}
}

void	sort(t_push *swap)
{
	swap->a = ft_index(swap);
	if (swap->lena == 2)
	{
		sort_two(swap);
		return ;
	}
	if (swap->lena == 3)
	{
		sort_three(swap);
		return ;
	}
	else if (swap->lena == 4)
	{
		sort_four(swap);
		return ;
	}
	else if (swap->lena == 5)
	{
		sort_five(swap);
		return ;
	}
	else
		sort_radix(swap);
}
