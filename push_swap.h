/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:56:41 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/29 14:05:18 by qestefan         ###   ########.fr       */
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
	int			*arg;
}	t_getarg;

int			ft_masslen(int *array);
int			*ft_strjoin_int(int *s1, int *s2, int counter, int count);
int			*ft_strdup_int(const int *s1, int count);
int			*save_buffer(int *arguments, int *buffer, int count, int counter);
int			*fill_array(int *buffer, char **str, int count);
int			ft_arrlen(char **str);
void		ft_free(char **str);
void		ft_perror(char *str);
void		check_repeats(int *arg, int counter);
void		check_sort(int *arg, int len);
t_getarg	get_argv(char **argv, int argc, t_getarg getav);
// t_stack		*fill_list(t_getarg getav, t_stack *a);

#endif
