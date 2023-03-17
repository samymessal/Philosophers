/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:38:54 by smessal           #+#    #+#             */
/*   Updated: 2023/03/17 18:51:56 by smessal          ###   ########.fr       */
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
		if (philo->index == 1 && philo->num_philo > 1)
			first_philo(philo, last);
		else if (philo->index == 1 && philo->num_philo == 1)
			one_philo(philo);
		else
			other_philo(philo, prev);
		if (philo->num_philo > 1)
        	thinking(philo);
	}
    return (NULL);
}

void	*start_checker(void *arg)
{
	t_data	*data;
	
	data = (t_data *)arg;
	usleep(1000000);
	while (1)
	{
		if (dies(data))
		{
			pthread_mutex_lock(&data->mut_print);
			// pthread_mutex_lock(&data->philo_died->fork);
			printf("%s died\n", data->philo_died->val_c);
			// pthread_mutex_unlock(&data->philo_died->fork);
			// pthread_mutex_unlock(&data->mut_print);
			// free_data(data);
			// free_philo(data->philo);
			exit (0);
		}
	}
	return (NULL);
}