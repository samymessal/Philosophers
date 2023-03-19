/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:38:54 by smessal           #+#    #+#             */
/*   Updated: 2023/03/19 15:12:09 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	conditions_routine(t_philo *philo, t_philo *last, t_philo *prev)
{
	if (philo->index == 1 && philo->num_philo > 1)
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

void	think_and3(t_philo *philo)
{
	time_t	time;

	time = philo->t_eat - philo->t_sleep;
	if (time < 0)
		time = philo->t_eat;
	if (philo->num_philo > 1)
	{
		thinking(philo);
		if (philo->num_philo == 3)
			usleep_me(philo->t_eat);
		else if (philo->index % 2 != 0)
			usleep_me(1000);
	}
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
		usleep_me(philo->t_die / 3);
	while (1)
	{
		pthread_mutex_lock(&philo->data->mut_end);
		end = philo->data->end;
		pthread_mutex_unlock(&philo->data->mut_end);
		if (end)
			return (NULL);
		if (!conditions_routine(philo, last, prev))
			return (NULL);
		think_and3(philo);
		if (philo->times_eat == philo->count)
			return (NULL);
	}
	return (NULL);
}
