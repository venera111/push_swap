/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:10:58 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/31 19:46:18 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	shift_to_b(t_stack *a, t_stack *b, int mid)
{
	while (a->len > 3)
	{
		if (a->start->num <= mid)
		{
			push(a, b);
			write(1, "pb\n", 3);

		}
	}
}

t_stack	*get_b(t_stack *a)
{
	int		i;
	t_stack	*b;

	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		ft_perror();
	b->start = NULL;
	b->len = 0;
	if (a->len < 3)
		return (b);
	else if (!check_sort_list(a) && a->len > 3)
		shift_to_b(a, b, a->mid);
	return (b);
}
