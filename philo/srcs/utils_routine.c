/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:01:50 by smessal           #+#    #+#             */
/*   Updated: 2023/03/19 11:41:57 by smessal          ###   ########.fr       */
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
		index_1(philo);
	else if (philo->index == 2)
		index_2(philo);
	else
		index_3(philo);
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
