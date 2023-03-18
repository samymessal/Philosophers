/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:39:50 by smessal           #+#    #+#             */
/*   Updated: 2023/03/18 23:16:17 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*-----Demander pour les free struct timeval------*/

int	dies(t_data *data)
{
	t_philo	*philo;
	time_t	time;
	long	count;

	philo = data->philo;
	// usleep(philo->t_die);
	count = 0;
	while (1 && philo)
	{
		time = timer();
		pthread_mutex_lock(&philo->mut_count);
        pthread_mutex_lock(&philo->mut_ate);
		if (time - philo->ate >= data->t_die && philo->times_eat != philo->count)
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
			return (1);
        }
		if (philo->times_eat == philo->count)
			count++;
        pthread_mutex_unlock(&philo->mut_ate);
		pthread_mutex_unlock(&philo->mut_count);
        philo = philo->next;
		if (count == data->num_philo)
		{
			pthread_mutex_lock(&data->mut_end);
			data->end = 1;
			pthread_mutex_unlock(&data->mut_end);
			return (1);
		}
		if (!philo)
		{	
            count = 0;
			philo = data->philo;
			// usleep(philo->t_eat);
		}
	}
	return (0);
}
