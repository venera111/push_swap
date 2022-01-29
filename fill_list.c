/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:36:20 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/29 14:06:57 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_repeats(int *arg, int counter)
{
	int	i;

	i = 0;
	while (i < counter - 1)
	{
		if (arg[i] == arg[i + 1])
			ft_perror("Error\n");
		i++;
	}
}

void	check_sort(int *arg, int len)
{
	int	i;
	int	tmp;
	int	counter;

	i = 0;
	counter = 1;
	while (counter)
	{
		counter = 0;
		while (i < (len - 1))
		{
			if (arg[i] > arg[i + 1])
			{
				tmp = arg[i];
				arg[i] = arg[i + 1];
				arg[i + 1] = tmp;
				counter = 1;
			}
			i++;
		}
		i = 0;
	}
}

t_stack	*fill_list(t_getarg getav, t_stack *a)
{
	t_list	*new;
	int 	i;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		ft_perror("Error\n");
	return (a);
}
