/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:54:59 by smessal           #+#    #+#             */
/*   Updated: 2023/03/16 17:57:06 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	locker(t_philo *philo, t_philo *prev)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->fork1);
		pthread_mutex_lock(&prev->fork1);
	}
	else
	{
		pthread_mutex_lock(&prev->fork1);
		pthread_mutex_lock(&philo->fork1);
	}
}

void	unlocker(t_philo *philo, t_philo *prev)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_unlock(&philo->fork1);
		pthread_mutex_unlock(&prev->fork1);
	}
	else
	{
		pthread_mutex_unlock(&prev->fork1);
		pthread_mutex_unlock(&philo->fork1);
	}
}