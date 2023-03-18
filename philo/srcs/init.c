/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:40:59 by smessal           #+#    #+#             */
/*   Updated: 2023/03/18 16:20:09 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(char **av, t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = lst_new(av, 0, data);
	if (!philo)
		return (NULL);
	i = 1;
	while (i < ft_atol(av[1]))
	{
		lst_addback(&philo, lst_new(av, i, data));
		i++;
	}
	return (philo);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->philo = NULL;
	data->end = 0;
	data->t_die = 0;
	data->time = 0;
	data->num_philo = 0;
	data->eats_time = -2;
	data->philosophers = NULL;
	data->time = timer();
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_end, NULL);
	pthread_mutex_init(&data->mut_time, NULL);
	return (data);
}

void	init_data2(char **av, t_data **data, t_philo *philo)
{
	if (av[5])
		(*data)->eats_time = ft_atol(av[5]);
	(*data)->philo = philo;
	(*data)->num_philo = ft_atol(av[1]);
	(*data)->t_die = philo->t_die / 1000;
}
