/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:38:54 by smessal           #+#    #+#             */
/*   Updated: 2023/03/18 23:17:42 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	conditions_routine(t_philo *philo, t_philo *last, t_philo *prev)
{
	
	if (philo->num_philo == 3)
	{
		three_philos(philo);
	}
	else if (philo->index == 1 && philo->num_philo > 1)
		first_philo(philo, last);
	else if (philo->index == 1 && philo->num_philo == 1)
	{
		one_philo(philo);
		return (0);
	}
	else
		other_philo(philo, prev);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_philo	*last;
	t_philo	*prev;
	int		end;

	philo = (t_philo *)arg;
	last = lst_last(philo);
	prev = philo->prev;
	if (philo->index % 2 == 0 && philo->num_philo > 1)
		usleep(philo->t_eat - philo->t_sleep);
	while (1)
	{
		// printf("index: %d test\n", philo->index);
		pthread_mutex_lock(&philo->data->mut_end);
		end = philo->data->end;
		pthread_mutex_unlock(&philo->data->mut_end);
		if (end)
			return (NULL);
		if (!conditions_routine(philo, last, prev))
			return (NULL);
		if (philo->num_philo > 1)
		{
			thinking(philo);
			// usleep(philo->t_eat - philo->t_sleep);
		}
		if (philo->times_eat == philo->count)
			return (NULL);
	}
	return (NULL);
}
