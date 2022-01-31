/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:19:07 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/31 18:25:14 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
