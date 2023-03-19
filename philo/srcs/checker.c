/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:39:50 by smessal           #+#    #+#             */
/*   Updated: 2023/03/19 12:16:44 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simul(t_data *data, t_philo *philo, time_t time)
{
	data->philo_died = philo;
	pthread_mutex_lock(&data->mut_end);
	data->end = 1;
	pthread_mutex_unlock(&data->mut_end);
	pthread_mutex_lock(&philo->data->mut_time);
	pthread_mutex_lock(&data->mut_print);
	printf("%ld %s died\n", time - data->time, data->philo_died->val_c);
	pthread_mutex_unlock(&data->mut_print);
	pthread_mutex_unlock(&data->mut_time);
	pthread_mutex_unlock(&philo->mut_ate);
	pthread_mutex_unlock(&philo->mut_count);
}

void	d_mutex(pthread_mutex_t *mut1, pthread_mutex_t *mut2, int lock)
{
	if (lock == 1)
	{
		pthread_mutex_lock(mut1);
		pthread_mutex_lock(mut2);
	}
	else
	{
		pthread_mutex_unlock(mut1);
		pthread_mutex_unlock(mut2);
	}
}

void	set_end(t_data *data)
{
	pthread_mutex_lock(&data->mut_end);
	data->end = 1;
	pthread_mutex_unlock(&data->mut_end);
}

int	reinit_boucle(t_data *data, long *count, t_philo **philo)
{
	if (*count == data->num_philo)
	{
		set_end(data);
		return (1);
	}
	if (!(*philo))
	{
		*count = 0;
		*philo = data->philo;
	}
	return (0);
}

int	dies(t_data *data)
{
	t_philo	*philo;
	time_t	time;
	long	count;

	philo = data->philo;
	count = 0;
	while (1 && philo)
	{
		time = timer();
		d_mutex(&philo->mut_count, &philo->mut_ate, 1);
		if (time - philo->ate >= data->t_die
			&& philo->times_eat != philo->count)
		{
			end_simul(data, philo, time);
			return (1);
		}
		if (philo->times_eat == philo->count)
			count++;
		d_mutex(&philo->mut_ate, &philo->mut_count, 0);
		philo = philo->next;
		if (reinit_boucle(data, &count, &philo))
			return (1);
	}
	return (0);
}
