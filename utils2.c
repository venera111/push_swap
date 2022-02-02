/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:57:37 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/02 15:31:25 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_stack(t_stack *stack)
{
	if ((stack->start)->num < stack->min)
		stack->min = (stack->start)->num;
	if ((stack->start)->num > stack->max)
		stack->max = (stack->start)->num;
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

void	ft_perror(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	ft_atoi_swap(char *str)
{
	int			i;
	int			neg;
	long long	res;

	i = 0;
	res = 0;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + neg * (str[i] - 48);
		i++;
		if (res > 2147483647 || res < -2147483648)
			ft_perror();
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		ft_perror();
	return (res);
}
