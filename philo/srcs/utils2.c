/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:06:08 by smessal           #+#    #+#             */
/*   Updated: 2023/03/19 14:44:33 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	numlen(long long int num)
{
	int	i;

	i = 0;
	if (num == LONG_MIN)
		return (20);
	if (num < 0)
	{
		return (-1);
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	is_numeric(char *str)
{
	if (numlen(ft_atol(str)) == ft_strlen(str))
		return (1);
	return (0);
}

int	usleep_me(time_t rest)
{
	struct timeval	tv;
	struct timeval	start;
	long int		need;

	gettimeofday(&start, NULL);
	need = 0;
	rest /= 1000;
	while (need < rest)
	{
		gettimeofday(&tv, NULL);
		need = (tv.tv_sec - start.tv_sec) * 1000
			+ (tv.tv_usec - start.tv_usec) / 1000;
		usleep(30);
	}
	return (1);
}
