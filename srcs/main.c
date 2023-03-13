/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:41:37 by smessal           #+#    #+#             */
/*   Updated: 2023/03/13 23:25:44 by smessal          ###   ########.fr       */
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
    while (i < ft_atoi(av[1]))
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
	pthread_mutex_init(&data->mut_print, NULL);
	// pthread_mutex_init(&data->mut_ate, NULL);
	return (data);	
}

int main(int ac, char **av)
{
    if (ac != 5)
        return (0);
    int         num_philo;
    int         i;
    pthread_t   *philosophers;
	pthread_t	checker;
	t_data		*data;
    t_philo		*philo;

    num_philo = ft_atoi(av[1]);
	data = init_data();
    philo = init_philo(av, data);
	data->philo = philo;
    philosophers = malloc(sizeof(pthread_t) * num_philo);
    if (!philosophers)
        return (1);
    i = 0;
    while (i < num_philo && philo)
    {
		pthread_create(&philosophers[i], NULL, &start_pair, &(*philo));
        philo = philo->next;
		i++;
    }
    i = 0;
    while (i < num_philo)
    {
		pthread_join(philosophers[i], NULL);
		i++;
    }
	pthread_create(&checker, NULL, &start_checker, &(*data));
	pthread_join(checker, NULL);
    return (0);
}