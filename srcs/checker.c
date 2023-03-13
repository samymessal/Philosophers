/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:39:50 by smessal           #+#    #+#             */
/*   Updated: 2023/03/13 17:27:49 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*-----Demander pour les free struct timeval------*/

int philo_ate(void)
{
    struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec);
}

int	calc_eat(struct timeval time, int ate)
{
	int	i;
	int	j;
	int	result;

	i = time.tv_usec;
	j = ate;
	result = 0;
	if (j < i)
	{
		result = i - j;
		result = 1000000 - result;
	}
	else
		result = j - i;
	return (result);
}

int	dies(t_data *data)
{
	int				i;
	t_philo			*philo;
	struct timeval	time;

	i = 0;
	philo = data->mutex;
	while (philo && philo[i].ate)
	{
		gettimeofday(&time, NULL);
		if (calc_eat(time, philo[i].ate) >= data->t_die)
			return (1);
		i++;
	}
	return (0);
}
