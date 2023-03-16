/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:38:54 by smessal           #+#    #+#             */
/*   Updated: 2023/03/16 17:58:37 by smessal          ###   ########.fr       */
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
		usleep(philo->t_eat / 2);
	while (1)
	{
		tfork(philo);
		if (philo->index == 1)
		{
			locker(philo, last);
			tfork(philo);
            eat(philo);
            usleep(philo->t_eat);
			pthread_mutex_lock(&philo->mut_ate);
			philo->ate = philo_ate();
			pthread_mutex_unlock(&philo->mut_ate);
			unlocker(philo, last);
            sleeping(philo);
            usleep(philo->t_sleep);
		}
		else
		{
			locker(philo, prev);
			tfork(philo);
            eat(philo);
            usleep(philo->t_eat);
			pthread_mutex_lock(&philo->mut_ate);
			philo->ate = philo_ate();
			pthread_mutex_unlock(&philo->mut_ate);
			unlocker(philo, prev);
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
	usleep(1000);
	while (1)
	{
		if (dies(data))
		{
			pthread_mutex_lock(&data->mut_print);
			pthread_mutex_lock(&data->philo_died->fork1);
			printf("%s died\n", data->philo_died->val_c);
			pthread_mutex_unlock(&data->philo_died->fork1);
			pthread_mutex_unlock(&data->mut_print);
			break ;
		}
	}
	return (NULL);
}