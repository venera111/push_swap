/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:26:59 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/31 21:49:53 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack) // меняем местами два первых элемента
{
	t_lst	*temp;

	if (stack->len < 2)
		return ;
	temp = stack->start->next; //сохраняем адрес второй ноды
	stack->start->next = stack->start->next->next;// по указателю второй ноды хранится третья
	temp->next = stack->start; // вслед за вторым эл сохраняем первый в temp
	stack->start = temp; //добавляем указатель в начало списка
}

void	reverse_rotate(t_stack *stack) // последний элемент становится первым
{
	t_lst	*lst;
	t_lst	*temp;

	if (stack->len < 2)
		return ;
	lst = lst_n_elem(stack, stack->len - 1);
	temp = lst->next;
	lst->next = NULL;
	temp->next = stack->start;
	stack->start = temp;
}

void	push(t_stack *a, t_stack *b) // разобрать
{
	t_lst	*temp;

	if (a->len == 0)
		return ;
	temp = a->start;
	a->start = temp->next;
	temp->next = b->start;
	b->start = temp;
	a->len--;
	b->len++;
}

void	rotate(t_stack *stack) // разобрать
{
	t_lst	*temp;

	if (stack->len < 2)
		return ;
	temp = stack->start;
	lst_n_elem(stack, stack->len)->next = temp;
	stack->start = temp->next;
	temp->next = NULL;
}
