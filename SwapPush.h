/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SwapPush.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenumy <adenumy@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:21:49 by naterrie          #+#    #+#             */
/*   Updated: 2023/03/07 23:47:53 by adenumy          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPPUSH_H
# define SWAPPUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct pushswap
{
	int	*a;
	int	*b;
	int	lena;
	int	lenb;
}		t_push;

void	sort(t_push *swap);

char	**ft_split(char const *s, char c);
int		checksame(t_push *swap);
void	free_str(char **str, int len);

int		sort_check(t_push *swap);
void	sort_two(t_push *swap);
void	sort_three(t_push *swap);
void	sort_four(t_push *swap);

int		set_pushwap_args(char **args, t_push *push);
int		check_minusargs(char **args);

int		set_pushwap_arg(char **args, t_push *push);
int		check_minusarg(char **args);

void	sa(t_push *swap);
void	pa(t_push *swap);
void	pb(t_push *swap);

void	ra(t_push *swap);

void	rra(t_push *swap);

void	printcolonnes(t_push *swap);

#endif
