/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:56:41 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/28 12:01:04 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h> // malloc free
#include <stdio.h> // printf

typedef struct s_getarg
{
	int			counter;
	int			count;
	int			i;
	int			k;
	char		**str;
	int			*buff;
}	t_getarg;

int		ft_masslen(int *array);
int		*ft_strjoin_int(int *s1, int *s2, int counter, int count);
int		*ft_strdup_int(const int *s1, int count);
void	get_argv(char **argv, int argc);
int		*save_buffer(int *arguments, int *buffer, int count, int counter);
int		*fill_array(int *buffer, char **str, int count);
int		ft_arrlen(char **str);
void	ft_free(char **str);

#endif
