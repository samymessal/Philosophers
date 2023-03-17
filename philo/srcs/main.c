/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:41:37 by smessal           #+#    #+#             */
/*   Updated: 2023/03/18 00:41:47 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(char **av, t_data *data)
{
    int         i;
    t_philo    *philo;

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
	data->eats_time = 0;
	data->philosophers = NULL;
	data->time = timer();
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_end, NULL);
	pthread_mutex_init(&data->mut_time, NULL);
	return (data);	
}

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

int main(int ac, char **av)
{
    int         num_philo;
    int         i;
    pthread_t   *philosophers;
	// pthread_t	checker;
	t_data		*data;
    t_philo		*philo;

    if (ac < 5 || ac > 6)
	{
		ft_putstr_fd("Incorrect number of arguments\n", 2);
        return (1);
	}
	if (!valid_args(av))
	{
		ft_putstr_fd("Arguments must be numeric\n", 2);
		return (1);
	}
	num_philo = ft_atol(av[1]);
	data = init_data();
    philo = init_philo(av, data);
	if (av[5])
		data->eats_time = ft_atol(av[5]);
	data->philo = philo;
	data->t_die = philo->t_die / 1000;
    philosophers = malloc(sizeof(pthread_t) * num_philo);
    if (!philosophers)
		return (1);
	data->philosophers = philosophers;
    i = 0;
    while (i < num_philo && philo)
    {
		pthread_create(&philosophers[i], NULL, &routine, &(*philo));
        philo = philo->next;
		i++;
    }
	if (dies(data))
	{
		i = 0;
		while (i < num_philo)
		{
			pthread_join(philosophers[i], NULL);
			i++;
			// if (i == num_philo)
			// 	pthread_join(checker, NULL);
		}
		usleep(data->philo->t_die);
		check_locks(data);
		free_philo(data->philo);
		free_data(data);
		free_philos(philosophers);
		return (1);
	}
	// pthread_create(&checker, NULL, &start_checker, &(*data));
    return (0);
}
