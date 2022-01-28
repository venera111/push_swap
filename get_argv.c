/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:57:49 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/28 16:58:25 by qestefan         ###   ########.fr       */
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
	getav->cnt = 0;
	getav->cntr = 0;
	getav->i = 1;
	getav->k = 0;
}

t_getarg	get_argv(char **argv, int argc, t_getarg getav)
{
	init_getargv(&getav);
	while (argv[getav.i])
	{
		getav.str = ft_split(argv[getav.i], ' ');
		if (!getav.str || !*getav.str)
			ft_perror("Error\n");
		getav.cnt = ft_arrlen(getav.str);
		getav.cntr += getav.cnt;
		getav.buff = (int *)malloc(sizeof(int) * getav.cnt);
		if (!getav.buff)
			ft_perror("Error\n");
		getav.buff = fill_array(getav.buff, getav.str, getav.cnt);
		ft_free(getav.str);
		getav.arg = save_buffer(getav.arg, getav.buff, getav.cnt, getav.cntr);
		free(getav.buff);
		getav.i++;
	}
	free(getav.arg);
	check_repeats(getav.arg, getav.cntr);
	check_sort(getav.arg, getav.cntr);
	return (getav);
}
// while (getav.k < getav.cntr)
	// 	printf("%d\n", getav.arg[getav.k++]);
