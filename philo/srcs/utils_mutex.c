/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:17:22 by smessal           #+#    #+#             */
/*   Updated: 2023/03/18 18:18:24 by smessal          ###   ########.fr       */
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
