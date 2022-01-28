/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:55:51 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/28 11:42:29 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_arrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

void	get_argv(char **argv, int argc)
{
	int			i;
	// int			k;
	char		**str;
	int			count;
	int			*buffer;
	static int	*arguments;
	int			counter;

	count = 0;
	counter = 0;
	i = 1;
	while (argv[i])
	{
		str = ft_split(argv[i], ' ');
		count = ft_arrlen(str);
		counter += count;
		buffer = (int *)malloc(sizeof(int) * count);
		buffer = fill_array(buffer, str, count);
		ft_free(str);
		arguments = save_buffer(arguments, buffer, count, counter);
		free(buffer);
		i++;
	}
	// k = 0;
	// while (k < counter)
	// 	printf("%d\n", arguments[k++]);
	free(arguments);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	get_argv(argv, argc);
	return (0);
}
