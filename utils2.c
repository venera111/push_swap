/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:57:37 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/02 09:45:56 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_stack(t_stack *stack)
{
	if ((stack->start)->num < stack->min)
		stack->min = (stack->start)->num;
	if ((stack->start)->num > stack->max)
		stack->max = (stack->start)->num;
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

void	ft_perror(void)
{
	write(1, "Error\n", 6);
	exit(0);
}
