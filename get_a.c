/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:34:40 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/02 09:45:32 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_num(t_stack *stack, int num)
{
	int		n;
	t_lst	*lst;

	n = 0;
	lst = stack->start;
	while (lst && lst->num != num)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}

int	position(t_stack *stack, int num)
{
	int		n;
	t_lst	*lst;

	n = 0;
	if (num > stack->max)
		return (index_num(stack, stack->max) + 1);
	else if (num < stack->min)
		return (index_num(stack, stack->min));
	lst = stack->start;
	if (lst->num > num && (lst_n_elem(stack, stack->len))->num < num)
		return (0);
	while (lst && lst->next && !(lst->num < num && (lst->next)->num > num))
	{
		n++;
		lst = lst->next;
	}
	return (++n);
}

t_commands	get_move(int pos_a, int pos_b, int len_a, int len_b)
{
	t_commands	move;

	move.ra = pos_a;
	move.rb = pos_b;
	move.rra = len_a - pos_a;
	move.rrb = len_b - pos_b;
	move.f1 = ft_max(move.ra, move.rb);
	move.f2 = move.ra + move.rrb;
	move.f3 = move.rra + move.rb;
	move.f4 = ft_max(move.rra, move.rrb);
	return (move);
}

t_commands	min_move(t_stack *a, t_stack *b)
{
	int			min;
	int			pos_b;
	t_lst		*lst_b;
	t_commands	move;
	t_commands	min_move;

	min = a->len + b->len;
	pos_b = 0;
	lst_b = b->start;
	min_move = get_move(0, 0, 0, 0);
	while (lst_b)
	{
		move = get_move(position(a, lst_b->num), pos_b,
				a->len, b->len);
		if (min > ft_min(ft_min(move.f1, move.f2), ft_min(move.f3, move.f4)))
		{
			min_move = move;
			min = ft_min(ft_min(move.f1, move.f2), ft_min(move.f3, move.f4));
		}
		pos_b++;
		lst_b = lst_b->next;
	}
	return (min_move);
}

void	get_a(t_stack *a, t_stack *b)
{
	int			min;
	t_commands	move;

	while (b->start)
	{
		move = min_move(a, b);
		min = ft_min(ft_min(move.f1, move.f2), ft_min(move.f3, move.f4));
		if (move.f1 == min)
			move_1(a, b, move);
		else if (move.f2 == min)
			move_2(a, b, move);
		else if (move.f3 == min)
			move_3(a, b, move);
		else if (move.f4 == min)
			move_4(a, b, move);
		change_stack(a);
	}
}
