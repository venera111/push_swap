/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:56:41 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/31 19:09:54 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h> // malloc free
#include <stdio.h> // printf

typedef struct s_lst
{
	int				num;
	struct s_lst	*next;
}	t_lst;

typedef struct s_stack
{
	t_lst	*start;
	int		len;
	int		min;
	int		mid;
	int		max;
}	t_stack;

typedef struct s_getarg
{
	int			cntr;
	int			cnt;
	int			i;
	int			k;
	char		**str;
	int			*buff;
}	t_getarg;

int		ft_masslen(int *array);
int		*ft_strjoin_int(int *s1, int *s2, int counter, int count);
int		*ft_strdup_int(const int *s1, int count);
int		*save_buffer(int *array, int *buffer, int count, int counter);
int		*fill_array(int *buffer, char **str, int count);
int		ft_arrlen(char **str);
void	ft_free(char **str);
void	ft_perror(void);
void	check_repeats(int *arg, int counter);
void	check_sort(int *arg, int len);
t_stack	*get_argv(char **argv, int argc, t_getarg getav, t_stack *a);
t_stack	*fill_list(t_getarg getav, t_stack *a, int *array);
t_stack	*get_b(t_stack *a);
//sort
int		check_sort_list(t_stack *a);
void	sort_threenum(t_stack *a);
void	sort_threenum2(t_stack *a, int a1, int a2, int a3);

//lists
t_lst	*lstnew(int val);
t_lst	*lstnext(t_lst *lst, int val);
void	lstclear(t_lst **lst);
t_lst	*lst_n_elem(t_stack *stack, int n);

//comm
void	swap(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	push(t_stack *a, t_stack *b);

void	commands_count(t_stack *stack, void (*f)(t_stack *), int count);
void	shift_to_b(t_stack *a, t_stack *b, int mid);

#endif
