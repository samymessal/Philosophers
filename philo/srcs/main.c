/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:41:37 by smessal           #+#    #+#             */
/*   Updated: 2023/03/18 23:13:53 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_args(char **av)
{
	int	i;

	i = 1;
	while (av && av[i])
	{
		if (!is_numeric(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	thread_creat(pthread_t *philosophers, t_data *data)
{
	int		i;
	t_philo	*philo;

	data->philosophers = philosophers;
	philo = data->philo;
	i = 0;
	while (i < data->num_philo && philo)
	{
		pthread_create(&philosophers[i], NULL, &routine, &(*philo));
		philo = philo->next;
		i++;
	}
	if (dies(data))
	{
		i = 0;
		while (i < data->num_philo)
		{
			pthread_join(philosophers[i], NULL);
			i++;
		}
		usleep(data->philo->t_die);
		free_all(data, philosophers);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	pthread_t	*philosophers;
	t_data		*data;
	t_philo		*philo;

	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd("Incorrect number of arguments\n", 2);
		return (1);
	}
	if (!valid_args(av))
	{
		ft_putstr_fd("Arguments must be positive numbers\n", 2);
		return (1);
	}
	data = init_data();
	philo = init_philo(av, data);
	init_data2(av, &data, philo);
	philosophers = malloc(sizeof(pthread_t) * data->num_philo);
	if (!philosophers)
		return (free_all(data, NULL), 1);
	if (thread_creat(philosophers, data))
		return (1);
	return (0);
}
