/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:55:51 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/26 20:55:04 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	*get_argv(char **argv, int argc)
{
	int		i;
	int		k;
	char	**arguments;

	i = 1;
	k = 0;
	while (argv[i])
	{
		arguments[k] = ft_split(argv[i], ' ');
		i++;
		k++;
	}
}

int	main(int argc, char **argv)
{
	int	*arg;

	if (argv < 2)
		return (0);
	arg = get_argv(argv, argc);

	return (0);
}
