/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:01:50 by smessal           #+#    #+#             */
/*   Updated: 2023/03/16 18:12:32 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	first_philo(t_philo *philo, t_philo *last)
{
	locker(philo, last);
	tfork(philo);
	eat(philo);
	usleep(philo->t_eat);
	pthread_mutex_lock(&philo->mut_ate);
	philo->ate = timer();
	pthread_mutex_unlock(&philo->mut_ate);
	unlocker(philo, last);
	sleeping(philo);
	usleep(philo->t_sleep);
}

void	other_philo(t_philo *philo, t_philo *prev)
{
	locker(philo, prev);
	tfork(philo);
	eat(philo);
	usleep(philo->t_eat);
	pthread_mutex_lock(&philo->mut_ate);
	philo->ate = timer();
	pthread_mutex_unlock(&philo->mut_ate);
	unlocker(philo, prev);
	sleeping(philo);
	usleep(philo->t_sleep);
}
