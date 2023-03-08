/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenumy <adenumy@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:45:09 by adenumy           #+#    #+#             */
/*   Updated: 2023/03/07 16:10:39 by adenumy          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../SwapPush.h"
#include <stdio.h>

void	printcolonnes(t_push *push)
{
	int i;

	i = 0;
	printf("len a = %d\nlen b = %d\n", push->lena, push->lenb);
	while (i < push->lena)
	{
		printf("a[%d] = %d\n", i, push->a[i]);
		i++;
	}
	i = 0;
	while (i < push->lenb)
	{
		printf("b[%d] = %d\n", i, push->b[i]);
		i++;
	}
}
