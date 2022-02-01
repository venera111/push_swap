/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:19:07 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/01 14:17:37 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	commands_count(t_stack *stack, void (*f)(t_stack *), int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		f(stack);
		i++;
	}
}

void	rotate_count(t_stack *stack, int n)
{
	if (n - (stack->len) / 2 - (stack->len) % 2 > 0)
	{
		n = stack->len - n + 1;
		commands_count(stack, reverse_rotate, n);
		ft_write_count("rra\n", n);
	}
	else
	{
		n = n - 1;
		commands_count(stack, rotate, n);
		ft_write_count("ra\n", n);
	}
}

void	ft_write_count(char *str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		write(1, str, ft_strlen(str));
		i++;
	}
}
