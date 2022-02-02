/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:03:50 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/02 09:45:48 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_1(t_stack *a, t_stack *b, t_commands move)
{
	commands_count(a, rotate, move.ra);
	commands_count(b, rotate, move.rb);
	if (move.ra <= move.rb)
	{
		ft_write_count("rr\n", move.ra);
		ft_write_count("rb\n", move.rb - move.ra);
	}
	else
	{
		ft_write_count("rr\n", move.rb);
		ft_write_count("ra\n", move.ra - move.rb);
	}
	push(b, a);
	write(1, "pa\n", 3);
}

void	move_2(t_stack *a, t_stack *b, t_commands move)
{
	commands_count(a, rotate, move.ra);
	ft_write_count("ra\n", move.ra);
	commands_count(b, reverse_rotate, move.rrb);
	ft_write_count("rrb\n", move.rrb);
	push(b, a);
	write(1, "pa\n", 3);
}

void	move_3(t_stack *a, t_stack *b, t_commands move)
{
	commands_count(a, reverse_rotate, move.rra);
	ft_write_count("rra\n", move.rra);
	commands_count(b, rotate, move.rb);
	ft_write_count("rb\n", move.rb);
	push(b, a);
	write(1, "pa\n", 3);
}

void	move_4(t_stack *a, t_stack *b, t_commands move)
{
	commands_count(a, reverse_rotate, move.rra);
	commands_count(b, reverse_rotate, move.rrb);
	if (move.rra <= move.rrb)
	{
		ft_write_count("rrr\n", move.rra);
		ft_write_count("rrb\n", move.rrb - move.rra);
	}
	else
	{
		ft_write_count("rrr\n", move.rrb);
		ft_write_count("rra\n", move.rra - move.rrb);
	}
	push(b, a);
	write(1, "pa\n", 3);
}
