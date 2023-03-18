/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:01:50 by smessal           #+#    #+#             */
/*   Updated: 2023/03/18 23:14:44 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	first_philo(t_philo *philo, t_philo *last)
{
	locker(philo, last);
	eat(philo);
	pthread_mutex_lock(&philo->mut_count);
	philo->count++;
	pthread_mutex_unlock(&philo->mut_count);
	pthread_mutex_lock(&philo->mut_ate);
	philo->ate = timer();
	pthread_mutex_unlock(&philo->mut_ate);
	usleep(philo->t_eat);
	unlocker(philo, last);
	sleeping(philo);
	usleep(philo->t_sleep);
}

void	three_philos(t_philo *philo)
{
	if (philo->index == 1)
	{
		pthread_mutex_lock(&((t_philo *)(philo->next))->fork);
		tfork(philo);
		pthread_mutex_lock(&philo->fork);
		tfork(philo);
		eat(philo);
		pthread_mutex_lock(&philo->mut_count);
		philo->count++;
		pthread_mutex_unlock(&philo->mut_count);
		pthread_mutex_lock(&philo->mut_ate);
		philo->ate = timer();
		pthread_mutex_unlock(&philo->mut_ate);
		usleep(philo->t_eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&((t_philo *)(philo->next))->fork);
		sleeping(philo);
		usleep(philo->t_sleep);
	}
	else if (philo->index == 2)
	{
		pthread_mutex_lock(&philo->fork);
		tfork(philo);
		pthread_mutex_lock(&((t_philo *)(philo->prev))->fork);
		tfork(philo);
		eat(philo);
		pthread_mutex_lock(&philo->mut_count);
		philo->count++;
		pthread_mutex_unlock(&philo->mut_count);
		pthread_mutex_lock(&philo->mut_ate);
		philo->ate = timer();
		pthread_mutex_unlock(&philo->mut_ate);
		usleep(philo->t_eat);
		pthread_mutex_unlock(&((t_philo *)(philo->prev))->fork);
		pthread_mutex_unlock(&philo->fork);
		sleeping(philo);
		usleep(philo->t_sleep);
	}
	else
	{
		pthread_mutex_lock(&philo->fork);
		tfork(philo);
		pthread_mutex_lock(&philo->data->philo->fork);
		tfork(philo);
		eat(philo);
		pthread_mutex_lock(&philo->mut_count);
		philo->count++;
		pthread_mutex_unlock(&philo->mut_count);
		pthread_mutex_lock(&philo->mut_ate);
		philo->ate = timer();
		pthread_mutex_unlock(&philo->mut_ate);
		usleep(philo->t_eat);
		pthread_mutex_unlock(&philo->data->philo->fork);
		pthread_mutex_unlock(&philo->fork);
		sleeping(philo);
		usleep(philo->t_sleep);
	}
}

void	one_philo(t_philo *philo)
{
	tfork(philo);
    pthread_mutex_lock(&philo->mut_ate);
	philo->ate = timer();
	pthread_mutex_unlock(&philo->mut_ate);
}

void	other_philo(t_philo *philo, t_philo *prev)
{
	locker(philo, prev);
	eat(philo);
	pthread_mutex_lock(&philo->mut_count);
	philo->count++;
	pthread_mutex_unlock(&philo->mut_count);
	pthread_mutex_lock(&philo->mut_ate);
	philo->ate = timer();
	pthread_mutex_unlock(&philo->mut_ate);
	usleep(philo->t_eat);
	unlocker(philo, prev);
	sleeping(philo);
	usleep(philo->t_sleep);
}
