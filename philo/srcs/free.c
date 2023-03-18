/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:18:50 by smessal           #+#    #+#             */
/*   Updated: 2023/03/18 15:37:44 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void free_data(t_data *data)
{
	if (data)
	{
		pthread_mutex_destroy(&data->mut_print);
		pthread_mutex_destroy(&data->mut_time);
		pthread_mutex_destroy(&data->mut_end);
		free(data);
	}
}

void free_philo(t_philo *philo)
{
	t_philo *temp;

	temp = philo;
	while (temp)
	{
		if (temp->val_c)
			free(philo->val_c);
		pthread_mutex_destroy(&temp->mut_count);
		pthread_mutex_destroy(&temp->fork);
		pthread_mutex_destroy(&temp->mut_ate);
		temp = temp->next;
		free(philo);
		philo = temp;
	}
}

void	free_philos(pthread_t	*philosophers)
{
	if (philosophers)
		free(philosophers);
}
void	check_locks(t_data *data)
{
	t_philo *philo;

	philo = data->philo;
	while (philo)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(&philo->mut_count);
        pthread_mutex_lock(&philo->mut_ate);
		pthread_mutex_unlock(&philo->mut_ate);
		pthread_mutex_unlock(&philo->mut_count);
		pthread_mutex_unlock(&philo->fork);
		philo = philo->next;
	}
	pthread_mutex_lock(&data->mut_print);
	pthread_mutex_unlock(&data->mut_print);
}

void	free_all(t_data *data, pthread_t *philosophers)
{
	check_locks(data);
	free_philo(data->philo);
	free_data(data);
	free_philos(philosophers);
}