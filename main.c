/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:55:51 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/27 14:26:29 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int ft_arrlen(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int *fill_array(int *array, char **str, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		array[i] = ft_atoi(str[i]);
		i++;
	}
	return (array);
}

int	*save_buffer(int *str, int *buffer)
{
	
}

void get_argv(char **argv, int argc)
{
	int			i;
	int 		k;
	char		**str;
	int			count;
	int			*buffer;
	static int	*arguments;

	count = 0;
	i = 1;
	while (argv[i])
	{
		k = 0;
		str = ft_split(argv[i], ' ');
		count = ft_arrlen(str);
		buffer = (int *)malloc(sizeof(int) * count);
		buffer = fill_array(array, str, count);
		ft_free(str);
		// конкатенация массивов int в один
		while (k < count)
		{
			arguments = save_buffer(arguments, buffer);
			k++;
		}
		free(buffer);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	get_argv(argv, argc);
	return (0);
}
