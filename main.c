/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:55:51 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/27 16:49:22 by qestefan         ###   ########.fr       */
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
	int	*temp;

	if (str)
	{
		temp = str;
		str = ft_strjoin_int(str, buffer);
		free(temp);
	}
	else
		str = ft_strdup_int(buffer);
	return (str);
}

void get_argv(char **argv, int argc)
{
	int			i;
	int			k;
	char		**str;
	int			count;
	int			*buffer;
	static int	*arguments;

	count = 0;
	i = 1;
	while (argv[i])
	{
		str = ft_split(argv[i], ' ');
		count = ft_arrlen(str);
		buffer = (int *)malloc(sizeof(int) * count);
		if (!buffer)
			perror("No allocate!");
		buffer = fill_array(buffer, str, count);
		ft_free(str);
		k = 0;
		// while (k < count) // печать буфера (одного аргумента)
		// 	printf("%d\n", buffer[k++]);
		arguments = save_buffer(arguments, buffer);
		free(buffer);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		printf("%d ", arguments[i]);
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
