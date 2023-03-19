/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:58:01 by smessal           #+#    #+#             */
/*   Updated: 2023/03/19 10:59:32 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	index_1(t_philo *philo)
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

void	index_2(t_philo *philo)
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

void	index_3(t_philo *philo)
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
