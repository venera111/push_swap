/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:55:51 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/30 14:41:21 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_getarg	getav;
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		return (0);
	a = get_argv(argv, argc, getav, a);
	//
	while (a->start)
	{
		printf("%d ", a->start->num);
		a->start = a->start->next;
	}
	//
	lstclear(&(a->start));
	free(a);
	return (0);
}
