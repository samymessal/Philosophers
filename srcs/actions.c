/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:53:32 by smessal           #+#    #+#             */
/*   Updated: 2023/03/12 14:12:17 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    tfork(t_philo philo)
{
    printf("%d takes fork\n", philo.index);
}

void    eat(t_philo philo)
{
    printf("%d is eating\n", philo.index);
}

void    sleeping(t_philo philo)
{
    printf("%d is sleeping\n", philo.index);
}

void    thinking(t_philo philo)
{
    printf("%d is thinking\n", philo.index);
}