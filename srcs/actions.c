/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:53:32 by smessal           #+#    #+#             */
/*   Updated: 2023/03/10 18:59:22 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    eat(t_thread philo)
{
    printf("%d is eating\n", philo.index);
}

void    sleeping(t_thread philo)
{
    printf("%d is sleeping\n", philo.index);
}

void    thinking(t_thread philo)
{
    printf("%d is thinking\n", philo.index);
}