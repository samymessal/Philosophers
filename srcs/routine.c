/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:38:54 by smessal           #+#    #+#             */
/*   Updated: 2023/03/12 15:43:27 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *start_pair(void *arg)
{
    t_philo *test;
	t_data	*data;
	int		index;

	data = (t_data *)arg;
    index = data->index;
	test = data->mutex;
    while (1)
	{
		pthread_mutex_lock(&test[index].mutex);
		if (index == 0)
		{
			pthread_mutex_lock(&test[data->num_philo - 1].mutex);
			tfork(test[index]);
            eat(test[index]);
            usleep(data->t_eat);
			pthread_mutex_unlock(&test[data->num_philo - 1].mutex);
		    pthread_mutex_unlock(&test[index].mutex);
            sleeping(test[index]);
            usleep(data->t_sleep);
		}
		else
		{
			pthread_mutex_lock(&test[index - 1].mutex);
			tfork(test[index]);
            eat(test[index]);
            usleep(data->t_eat);
			pthread_mutex_unlock(&test[index - 1].mutex);
		    pthread_mutex_unlock(&test[index].mutex);
            sleeping(test[index]);
            usleep(data->t_sleep);
		}
        thinking(test[index]);
        usleep(3);
	}
    return (NULL);
}

void    *start_impair(void *arg)
{
    t_philo *test;
	t_data	*data;
	int		index;

	data = (t_data *)arg;
    index = data->index;
	test = data->mutex;
    while (1)
	{
		pthread_mutex_lock(&test[index].mutex);
		if (index == 0)
		{
			pthread_mutex_lock(&test[data->num_philo - 1].mutex);
			tfork(test[index]);
            eat(test[index]);
            usleep(data->t_eat);
			pthread_mutex_unlock(&test[data->num_philo - 1].mutex);
		    pthread_mutex_unlock(&test[index].mutex);
            sleeping(test[index]);
            usleep(data->t_sleep);
		}
		else
		{
			pthread_mutex_lock(&test[index - 1].mutex);
			tfork(test[index]);
            eat(test[index]);
            usleep(data->t_eat);
			pthread_mutex_unlock(&test[index - 1].mutex);
		    pthread_mutex_unlock(&test[index].mutex);
            sleeping(test[index]);
            usleep(data->t_sleep);
		}
        thinking(test[index]);
        usleep(3);
	}
    return (NULL);
}
