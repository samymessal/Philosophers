/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:41:37 by smessal           #+#    #+#             */
/*   Updated: 2023/03/12 15:15:58 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_mutex(char **av)
{
    int         i;
    t_philo    *temp;

    i = 0;
    temp = malloc(sizeof(t_philo) * ft_atoi(av[1]));
    if (!temp)
        return (NULL);
    while (i < ft_atoi(av[1]))
    {
        temp[i].index = i;
        temp[i].val_c = ft_itoa(i);
        pthread_mutex_init(&temp[i].mutex, NULL);
        i++;
    }
	return (temp);
}

t_data	init_data(t_philo *mutex, char **av)
{
	t_data	data;

	// data = malloc(sizeof(t_data));
	// if (!data)
	// 	return (NULL);
	data.index = 0;
	data.num_philo = 0;
	data.num_philo = ft_atoi(av[1]);
	data.t_die = ft_atoi(av[2]);
	data.t_eat = ft_atoi(av[3]);
	data.t_sleep = ft_atoi(av[4]);
	data.mutex = NULL;
	pthread_mutex_init(&data.mut_ind, NULL);
	data.mutex = mutex;
	return (data);	
}

int main(int ac, char **av)
{
    if (ac > 5)
        return (0);
    int         num_philo;
    int         i;
    pthread_t   *philosophers;
	t_data		data;
    t_philo    *mutex;

    num_philo = ft_atoi(av[1]);
    mutex = init_mutex(av);
	data = init_data(mutex, av);
    philosophers = malloc(sizeof(pthread_t) * num_philo);
    if (!philosophers)
        return (1);
    i = 0;
    while (i < num_philo)
    {
		data.index = i;
		if (i % 2 == 0)
			pthread_create(&philosophers[i], NULL, &start_pair, &data);
		else
			pthread_create(&philosophers[i], NULL, &start_impair, &data);
		usleep(5);
		i++;
    }
    i = 0;
    while (i < num_philo)
    {
		pthread_join(philosophers[i], NULL);
		i++;
    }
    return (0);
}