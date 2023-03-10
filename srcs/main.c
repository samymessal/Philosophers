/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:41:37 by smessal           #+#    #+#             */
/*   Updated: 2023/03/10 19:11:24 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *start(void *arg)
{
    t_thread *test;
	t_data	*data;
	int		index;

	data = (t_data *)arg;
	// pthread_mutex_lock(&data->mut_ind);
	test = data->mutex;
    index = data->index;
	while (1)
	{
		pthread_mutex_lock(&test[index].mutex);
		if (index == data->num_philo - 1)
		{
			pthread_mutex_lock(&test[0].mutex);
			printf("%d takes fork\n", test[index].index);
			printf("%d is eating\n", test[index].index);
			usleep(5);
			printf("%d is sleeping\n", test[index].index);
			usleep(3);
			pthread_mutex_unlock(&test[index].mutex);
			pthread_mutex_unlock(&test[0].mutex);
		}
		else
		{
			pthread_mutex_lock(&test[index + 1].mutex);
			printf("%d takes fork\n", test[index].index); 
			printf("%d is eating\n", test[index].index);
			usleep(5);
			printf("%d is sleeping\n", test[index].index);
			usleep(3);
			pthread_mutex_unlock(&test[index + 1].mutex);
		}
		pthread_mutex_unlock(&test[index].mutex);
	}
	// pthread_mutex_unlock(&data->mut_ind);
    return (NULL);
}

t_thread	*init_mutex(char **av)
{
    int         i;
    t_thread    *temp;

    i = 0;
    temp = malloc(sizeof(t_thread) * ft_atoi(av[1]));
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

t_data	init_data(t_thread *mutex, char **av)
{
	t_data	data;

	// data = malloc(sizeof(t_data));
	// if (!data)
	// 	return (NULL);
	data.index = 0;
	data.num_philo = 0;
	data.num_philo = ft_atoi(av[1]);
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
    t_thread    *mutex;

    num_philo = ft_atoi(av[1]);
    mutex = init_mutex(av);
	data = init_data(mutex, av);
    philosophers = malloc(sizeof(pthread_t) * num_philo);
    if (!philosophers)
        return (1);
    i = 0;
    while (i < num_philo)
    {
        if (i % 2 == 0)
		{
			data.index = i;
			pthread_create(&philosophers[i], NULL, &start, &data);
		}
		i++;
    }
	i = 0;
	while (i < num_philo)
    {
        if (i % 2 == 0)
			pthread_join(philosophers[i], NULL);
		i++;
    }
	i = 0;
	while (i < num_philo)
    {
        if (i % 2 != 0)
		{
			data.index = i;
			pthread_create(&philosophers[i], NULL, &start, &data);
		}
		i++;
    }
    i = 0;
    while (i < num_philo)
    {
        if (i % 2 != 0)
		{
			pthread_join(philosophers[i], NULL);
		}
		i++;
    }
    return (0);
}