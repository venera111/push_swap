/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:55:51 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/01 11:56:46 by qestefan         ###   ########.fr       */
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
	a = get_argv(argv, argc, getav, a); // добавить ошибки на нецелое число и <= >= int
	b = get_b(a);
	if (a->len < 3)
	{
		if (!check_sort_list(a))
		{
			swap(a);
			write(1, "sa\n",3);
		}
	}
	else
		sort_threenum(a);
	get_a(a, b);
	rotate_count(a, index_num(a, a->min) + 1);
	lstclear(&(a->start));
	lstclear(&(b->start));
	free(a);
	free(b);
	return (0);
}
