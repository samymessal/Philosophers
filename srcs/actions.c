/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:53:32 by smessal           #+#    #+#             */
/*   Updated: 2023/03/13 23:23:39 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    tfork(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->mut_print);
    printf("%s takes fork\n", philo->val_c);
    pthread_mutex_unlock(&philo->data->mut_print);
}

void    eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->mut_print);
    printf("%s is eating\n", philo->val_c);
    pthread_mutex_unlock(&philo->data->mut_print);
}

void    sleeping(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->mut_print);
    printf("%s is sleeping\n", philo->val_c);
    pthread_mutex_unlock(&philo->data->mut_print);
}

void    thinking(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->mut_print);
    printf("%s is thinking\n", philo->val_c);
    pthread_mutex_unlock(&philo->data->mut_print);
}