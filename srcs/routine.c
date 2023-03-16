/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:38:54 by smessal           #+#    #+#             */
/*   Updated: 2023/03/16 18:49:22 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void *arg)
{
    t_philo *philo;
	t_philo	*last;
	t_philo	*prev;

	philo = (t_philo *)arg;
    last = lst_last(philo);
	prev = philo->prev;
	/*Est-ce vrmnt necessaire de sleep ?*/
	if (philo->index % 2 != 0)
		usleep(philo->t_eat / 2);
	while (1)
	{
		tfork(philo);
		if (philo->index == 1)
			first_philo(philo, last);
		else
			other_philo(philo, prev);
        thinking(philo);
	}
    return (NULL);
}

void	*start_checker(void *arg)
{
	t_data	*data;
	
	data = (t_data *)arg;
	// usleep(1000);
	while (1)
	{
		if (dies(data))
		{
			pthread_mutex_lock(&data->mut_print);
			// pthread_mutex_lock(&data->philo_died->fork);
			printf("%s died\n", data->philo_died->val_c);
			// pthread_mutex_unlock(&data->philo_died->fork);
			// pthread_mutex_unlock(&data->mut_print);
			exit (0);
		}
	}
	return (NULL);
}