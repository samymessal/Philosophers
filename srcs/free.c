/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:18:50 by smessal           #+#    #+#             */
/*   Updated: 2023/03/17 15:31:04 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	if (data)
	{
		pthread_mutex_destroy(&data->mut_print);
		pthread_mutex_destroy(&data->mut_time);
		free(data);
	}
}

void	free_philo(t_philo *philo)
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
