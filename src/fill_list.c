/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:36:20 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/01 14:17:27 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	check_repeats(int *arg, int counter)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (i < counter)
	{
		j = i + 1;
		while (j < counter)
		{
			if (arg[i] == arg[j])
				ft_perror();
			j++;
		}
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

int	check_sort_list(t_stack *a)
{
	t_lst	*temp;

	temp = a->start;
	while (temp && temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_stack	*fill_list(t_getarg getav, t_stack *a, int *array)
{
	t_lst	*new;
	int		i;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		ft_perror();
	new = lstnew(*array);
	a->start = new;
	a->len = getav.cntr;
	i = 1;
	while (i < getav.cntr)
		new = lstnext(new, *(array + i++));
	return (a);
}
