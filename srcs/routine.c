/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:38:54 by smessal           #+#    #+#             */
/*   Updated: 2023/03/13 23:20:00 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *start_pair(void *arg)
{
    t_philo *philo;
	t_philo	*last;
	t_philo	*prev;

	philo = (t_philo *)arg;
    last = lst_last(philo);
	prev = philo->prev;
	if (philo->index % 2 != 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		tfork(philo);
		if (philo->index == 0)
		{
			pthread_mutex_lock(&last->mutex);
			tfork(philo);
            eat(philo);
            usleep(philo->t_eat);
			philo->ate = philo_ate();
			pthread_mutex_unlock(&last->mutex);
		    pthread_mutex_unlock(&philo->mutex);
            sleeping(philo);
            usleep(philo->t_sleep);
		}
		else
		{
			pthread_mutex_lock(&prev->mutex);
			tfork(philo);
            eat(philo);
            usleep(philo->t_eat);
			philo->ate = philo_ate();
			pthread_mutex_unlock(&prev->mutex);
		    pthread_mutex_unlock(&philo->mutex);
            sleeping(philo);
            usleep(philo->t_sleep);
		}
        thinking(philo);
	}
    return (NULL);
}

void	*start_checker(void *arg)
{
	t_data	*data;
	
	data = (t_data *)arg;
	while (1)
	{
		if (dies(data))
		{
			printf("a philo died\n");
			exit(0);
		}
	}
}