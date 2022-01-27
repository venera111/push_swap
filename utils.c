/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:47:33 by qestefan          #+#    #+#             */
/*   Updated: 2022/01/27 16:47:39 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_masslen(int *array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	*ft_strjoin_int(int *s1, int *s2)
{
	int	*s3;
	int	len;

	if (!s1 || !s2)
		return ((void *)0);
	len = ft_masslen(s1) + ft_masslen(s2);
	s3 = (int *)malloc(sizeof(int) * (len + 1));
	if (!s3)
		return ((void *)0);
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	*s3++ = '\0';
	return (s3 - len - 1);
}

int	*ft_strdup_int(const int *s1)
{
	int	*result;
	int	i;

	i = 0;
	while (s1[i])
		i++;
	result = (int *)malloc(sizeof(int) * (i + 1));
	if (!result)
		return ((void *)0);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	result[i] = '\0';
	return (result);
}
