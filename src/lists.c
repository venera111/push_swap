/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:21:53 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/29 20:47:31 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
