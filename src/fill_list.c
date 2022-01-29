/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:36:20 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/29 21:16:34 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_repeats(int *arg, int counter)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (i < counter)
	{
		j = i+1;
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

t_stack	*fill_list(t_getarg getav, t_stack *a, int *array)
{
	t_lst	*new;
	int 	i;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		ft_perror();
	new = lstnew(*array); // add free
	a->start = new;
	a->len = getav.cntr;
	i = 1;
	while (i < getav.cntr)
		new = lstnext(new, *(array + i++)); // add free
	a->min = array[0];
	a->mid = array[a->len / 2];
	a->max = array[a->len - 1];
	return (a);
}

