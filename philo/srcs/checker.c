/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:39:50 by smessal           #+#    #+#             */
/*   Updated: 2023/03/17 23:20:59 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*-----Demander pour les free struct timeval------*/

int	dies(t_data *data)
{
	t_philo	*philo;
	time_t	time;

	philo = data->philo;
	usleep(philo->t_die);
	while (1 && philo)
	{
        pthread_mutex_lock(&philo->mut_ate);
		time = timer();
		if (time - philo->ate >= data->t_die)
		{
			data->philo_died = philo;
			printf("%ld %s died\n", time - data->time, data->philo_died->val_c);
			pthread_mutex_unlock(&philo->mut_ate);
			return (1);
        }
        pthread_mutex_unlock(&philo->mut_ate);
        philo = philo->next;
        if (!philo)
		{	
            philo = data->philo;
			usleep(philo->t_die);
		}
	}
	return (0);
}
