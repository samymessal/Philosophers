/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:41:37 by smessal           #+#    #+#             */
/*   Updated: 2022/12/27 04:32:10 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *start(void *arg)
{
    t_thread *test;

    test = (t_thread *)arg;
    pthread_mutex_lock(&test->mutex);
    printf("%d\n", test->value);
    test->value++;
    pthread_mutex_unlock(&test->mutex);
    return (NULL);
}

int main(int ac, char **av)
{
    if (ac > 5)
        return (0);
    int         num_philo;
    int         i;
    pthread_t   *philosophers;
    t_thread    mutex;
    
    num_philo = ft_atoi(av[1]);
    philosophers = malloc(sizeof(pthread_t) * num_philo);
    if (!philosophers)
        return (1);
    pthread_mutex_init(&mutex.mutex, NULL);
    i = 0;
    mutex.value = 0;
    while (i < num_philo)
    {
        pthread_create(&philosophers[i], NULL, &start, &mutex);
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