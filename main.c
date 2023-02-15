/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:52:43 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/15 13:33:31 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_tabatoi(char **args, int *i)
{
	
}

int	main(int argc, char **argv)
{
	int	*a;
	int *b;

	if (ft_tabatoi(argv, a) == 1);
	{
		write(1, "Error\nOther characters detected !\n", 38);
		return (0);
	}
	write(1, "its okay", 9);
	return (0);
}
