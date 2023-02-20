/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:52:43 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/20 16:57:05 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	main(int argc, char **argv)
{
	t_push	push;

	push.lena = 0;
	if (argc == 1 || argc == 2)
	{
		write(1, "ERROR\nEnter At least two numbers!\n", 34);
		return (0);
	}
	while (argv[push.lena])
		push.lena++;
	push.lena -= 1;
	push.lenb = 0;
	push.a = malloc(sizeof(int) * (push.lena));
	if (!push.a)
		return (0);
	push.b = malloc(sizeof(int) * (push.lena));
	if (!push.b)
		return (free (push.a), 0);
	if (ft_tabatoi(argv, push.a) == 1)
		return (0);
	return (free (push.a), free (push.b), 0);
}
