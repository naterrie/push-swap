/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SwapPush.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:21:49 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/21 18:34:34 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPPUSH_H
# define SWAPPUSH_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct pushswap
{
	int	*a;
	int	*b;
	int	lena;
	int	lenb;
}		t_push;

void	printcolonne(t_push *swap);

int		checksame(t_push *swap);
int		ft_tabatoi(char **args, t_push *swap);
int		set_pushwap(char **args, t_push *push);

void	sa(t_push *swap);
void	sb(t_push *swap);
void	ss(t_push *swap);

void	pa(t_push *swap);
void	pb(t_push *swap);

void	ra(t_push *swap);
void	rb(t_push *swap);
void	rr(t_push *swap);

void	rra(t_push *swap);
void	rrb(t_push *swap);
void	rrr(t_push *swap);

#endif