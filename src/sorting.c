/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:28:57 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/01 14:30:51 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	continue_sorting(t_stack *a)
{
	if (a->len < 3)
	{
		if (!check_sort_list(a))
		{
			swap(a);
			write(1, "sa\n", 3);
		}
	}
	else
		sort_threenum(a);
}

void	sort_threenum2(t_stack *a, int a1, int a2, int a3)
{
	if (a1 > a3 && a2 < a3)
	{
		commands_count(a, reverse_rotate, 2);
		ft_write_count("rra\n", 2);
	}
	if (a1 > a3 && a2 > a1)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	if (a1 > a2 && a2 > a3)
	{
		swap(a);
		write(1, "sa\n", 3);
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
}

void	sort_threenum(t_stack *a)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = a->start->num;
	a2 = a->start->next->num;
	a3 = a->start->next->next->num;
	if (a1 < a3 && a3 < a2)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
		swap(a);
		write(1, "sa\n", 3);
	}
	if (a1 > a2 && a1 < a3)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	sort_threenum2(a, a1, a2, a3);
	a->min = a->start->num;
	a->max = a->start->next->next->num;
}
