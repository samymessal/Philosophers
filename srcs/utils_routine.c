/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:01:50 by smessal           #+#    #+#             */
/*   Updated: 2023/03/17 19:01:03 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	locker(t_philo *philo, t_philo *prev)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->fork);
		tfork(philo);
		pthread_mutex_lock(&prev->fork);
		tfork(philo);
	}
	else
	{
		pthread_mutex_lock(&prev->fork);
		tfork(philo);
		pthread_mutex_lock(&philo->fork);
		tfork(philo);
	}
}

void	unlocker(t_philo *philo, t_philo *prev)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&prev->fork);
	}
	else
	{
		pthread_mutex_unlock(&prev->fork);
		pthread_mutex_unlock(&philo->fork);
	}
}

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

void	one_philo(t_philo *philo)
{
	tfork(philo);
	usleep(philo->t_die);
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
