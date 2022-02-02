/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:57:49 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/02 15:27:30 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_statistics(t_stack *a, int *array)
{
	a->min = array[0];
	a->mid = array[a->len / 2];
	a->max = array[a->len - 1];
}

int	*fill_array(int *buffer, char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		buffer[i] = ft_atoi_swap(str[i]);
		i++;
	}
	return (buffer);
}

int	*save_buffer(int *array, int *buffer, int count, int counter)
{
	int	*temp;

	if (array)
	{
		temp = array;
		array = ft_strjoin_int(array, buffer, counter, count);
		free(temp);
	}
	else
		array = ft_strdup_int(buffer, count);
	return (array);
}

void	init_getargv(t_getarg *getav)
{
	getav->cnt = 0;
	getav->cntr = 0;
	getav->i = 1;
	getav->k = 0;
}

t_stack	*get_argv(char **argv, t_getarg getav, t_stack *a)
{
	static int	*array;

	while (argv[getav.i])
	{
		getav.str = ft_split(argv[getav.i], ' ');
		if (!getav.str || !*getav.str)
			ft_perror();
		getav.cnt = ft_arrlen(getav.str);
		getav.cntr += getav.cnt;
		getav.buff = (int *)malloc(sizeof(int) * getav.cnt);
		if (!getav.buff)
			ft_perror();
		getav.buff = fill_array(getav.buff, getav.str, getav.cnt);
		ft_free(getav.str);
		array = save_buffer(array, getav.buff, getav.cnt, getav.cntr);
		free(getav.buff);
		getav.i ++;
	}
	a = fill_list(getav, a, array);
	check_repeats(array, getav.cntr);
	check_sort(array, getav.cntr);
	fill_statistics(a, array);
	free(array);
	return (a);
}
