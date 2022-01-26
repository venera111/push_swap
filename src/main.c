/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:55:51 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/26 23:31:48 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_arrlen(char **str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	*fill_array(char *array, char **arg)
{
	int	i;

	i = 0;
	while (arg[i])

	return (array);
}

void	get_argv(char **argv, int argc)
{
	int		i;
	char	***arg;
	int		count;
	int		*array;

	count = 0;
	arg = (char ***)malloc(sizeof(char *));
	i = 0;
	while (i < argc - 1)
	{
		arg[i] = (char **)malloc(sizeof(char **));
		arg[i] = ft_split(arg[i], ' ');
		count += ft_arrlen(arg[i]);
		i++;
	}
	array = (int *)malloc(sizeof(int) * count);
	array = fill_array(array, arg);
	free(arg); // и очистить **str и arg[i] в цикле в новой функции и **arg, array
}

int	main(int argc, char **argv)
{
	if (argv < 2)
		return (0);
	get_argv(argv, argc);
	return (0);
}
