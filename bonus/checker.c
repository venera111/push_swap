/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:58:21 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/02 07:19:19 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_swap2(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strncmp("ra\n", str, 3))
		rotate(a);
	if (!ft_strncmp("rb\n", str, 3))
		rotate(b);
	if (!ft_strncmp("rr\n", str, 3))
	{
		rotate(a);
		rotate(b);
	}
	if (!ft_strncmp("rra\n", str, 4))
		reverse_rotate(a);
	if (!ft_strncmp("rrb\n", str, 4))
		reverse_rotate(b);
	if (!ft_strncmp("rrr\n", str, 4))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	char	*str;

	str = NULL;
	str = get_next_line(0);
	while (str)
	{
		if (ft_strncmp("sa\n", str, 3))
			swap(a);
		if (!ft_strncmp("sb\n", str, 3))
			swap(b);
		if (!ft_strncmp("ss\n", str, 3))
		{
			swap(a);
			swap(b);
		}
		if (!ft_strncmp("pa\n", str, 3))
			push(b, a);
		if (!ft_strncmp("pb\n", str, 3))
			push(a, b);
		push_swap2(1, b, str);
		free(str);
		str = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack 	*b;
	t_getarg	getav;

	if (argc < 2)
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
	return (0);
}
