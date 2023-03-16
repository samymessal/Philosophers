/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:39:50 by smessal           #+#    #+#             */
/*   Updated: 2023/03/16 18:49:08 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*-----Demander pour les free struct timeval------*/

int	dies(t_data *data)
{
	t_philo	*philo;
	time_t	time;

	philo = data->philo;
	while (1 && philo)
	{
		time = timer();
        pthread_mutex_lock(&philo->mut_ate);
		if (philo->ate > 0 && time - philo->ate >= data->t_die)
		{
			data->philo_died = philo;
			pthread_mutex_unlock(&philo->mut_ate);
			return (1);
        }
        pthread_mutex_unlock(&philo->mut_ate);
        philo = philo->next;
        if (!philo)
            philo = data->philo;
	}
	return (0);
}
