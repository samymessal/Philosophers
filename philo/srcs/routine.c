/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:38:54 by smessal           #+#    #+#             */
/*   Updated: 2023/03/18 00:26:18 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void *arg)
{
    t_philo *philo;
	t_philo	*last;
	t_philo	*prev;
	int		end;

	philo = (t_philo *)arg;
    last = lst_last(philo);
	prev = philo->prev;
	end = 0;
	/*Est-ce vrmnt necessaire de sleep ?*/
	if (philo->index % 2 == 0 && philo->num_philo > 1)
		usleep(philo->t_die / 2);
	while (1)
	{
		pthread_mutex_lock(&philo->data->mut_end);
		end = philo->data->end;
		pthread_mutex_unlock(&philo->data->mut_end);
		if (end)
			return (NULL);
		if (philo->index == 1 && philo->num_philo > 1)
			first_philo(philo, last);
		else if (philo->index == 1 && philo->num_philo == 1)
		{
			one_philo(philo);
			return (NULL);
		}
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