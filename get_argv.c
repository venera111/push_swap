/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:57:49 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/28 12:00:00 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_array(int *buffer, char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		buffer[i] = ft_atoi(str[i]);
		i++;
	}
	return (buffer);
}

int	*save_buffer(int *arguments, int *buffer, int count, int counter)
{
	int	*temp;

	if (arguments)
	{
		temp = arguments;
		arguments = ft_strjoin_int(arguments, buffer, counter, count);
		free(temp);
	}
	else
		arguments = ft_strdup_int(buffer, count);
	return (arguments);
}

void	init_getargv(t_getarg *getav)
{
	getav->count = 0;
	getav->counter = 0;
	getav->i = 1;
	getav->k = 0;
}

void	get_argv(char **argv, int argc)
{
	static int	*arg;
	t_getarg	getav;

	init_getargv(&getav);
	while (argv[getav.i])
	{
		getav.str = ft_split(argv[getav.i], ' ');
		getav.count = ft_arrlen(getav.str);
		getav.counter += getav.count;
		getav.buff = (int *)malloc(sizeof(int) * getav.count);
		getav.buff = fill_array(getav.buff, getav.str, getav.count);
		ft_free(getav.str);
		arg = save_buffer(arg, getav.buff, getav.count, getav.counter);
		free(getav.buff);
		getav.i++;
	}
	while (getav.k < getav.counter)
		printf("%d\n", arg[getav.k++]);
	free(arg);
}
