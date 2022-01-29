/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:47:33 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/29 15:29:24 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_arrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_masslen(int *array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	*ft_strjoin_int(int *s1, int *s2, int counter, int count)
{
	int	*s3;
	int	len;
	int	i;
	int	k;

	if (!s1 || !s2)
		return ((void *)0);
	len = counter;
	s3 = (int *)malloc(sizeof(int) * len);
	if (!s3)
		return ((void *)0);
	i = 0;
	while (i < counter - count)
	{
		s3[i] = s1[i];
		i++;
	}
	k = 0;
	while (k < count)
	{
		s3[i] = s2[k];
		k++;
		i++;
	}
	return (s3);
}

int	*ft_strdup_int(const int *s1, int count)
{
	int	*result;
	int	i;

	result = (int *)malloc(sizeof(int) * count);
	if (!result)
		return ((void *)0);
	i = 0;
	while (i < count)
	{
		result[i] = s1[i];
		i++;
	}
	return (result);
}
