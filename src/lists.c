/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:21:53 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/01 14:17:07 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	lstdelone(t_lst *lst)
{
	if (!lst)
		ft_perror();
	else
		free(lst);
}

void	lstclear(t_lst **lst)
{
	t_lst	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			lstdelone(*lst);
			*lst = tmp;
		}
	}
}

t_lst	*lstnew(int val)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		ft_perror();
	new->num = val;
	new->next = NULL;
	return (new);
}

t_lst	*lstnext(t_lst *lst, int val)
{
	t_lst	*new;

	new = lstnew(val);
	if (lst)
		lst->next = new;
	return (new);
}

t_lst	*lst_n_elem(t_stack *stack, int n)
{
	t_lst	*lst;

	lst = stack->start;
	while (n > 1)
	{
		lst = lst->next;
		n--;
	}
	return (lst);
}
