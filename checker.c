/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:58:21 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/02 15:04:11 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap2(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp("ra\n", line, 3))
		rotate(a);
	if (!ft_strncmp("rb\n", line, 3))
		rotate(b);
	if (!ft_strncmp("rr\n", line, 3))
	{
		rotate(a);
		rotate(b);
	}
	if (!ft_strncmp("rra\n", line, 4))
		reverse_rotate(a);
	if (!ft_strncmp("rrb\n", line, 4))
		reverse_rotate(b);
	if (!ft_strncmp("rrr\n", line, 4))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	char	*line;

	line = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp("sa\n", line, 3))
			swap(a);
		if (!ft_strncmp("sb\n", line, 3))
			swap(b);
		if (!ft_strncmp("ss\n", line, 3))
		{
			swap(a);
			swap(b);
		}
		if (!ft_strncmp("pa\n", line, 3))
			push(b, a);
		if (!ft_strncmp("pb\n", line, 3))
			push(a, b);
		push_swap2(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_getarg	getav;

	if (argc == 1)
		return (0);
	a = NULL;
	init_getargv(&getav);
	a = get_argv(argv, getav, a);
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		ft_perror();
	b->start = NULL;
	b->len = 0;
	push_swap(a, b);
	if (check_sort_list(a) && a->len && !(b->len))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lstclear(&(a->start));
	lstclear(&(b->start));
	free(a);
	free(b);
	return (0);
}
