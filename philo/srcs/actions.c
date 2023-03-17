/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:53:32 by smessal           #+#    #+#             */
/*   Updated: 2023/03/18 00:06:30 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    tfork(t_philo *philo)
{
    time_t	time;
	int		end;

	end = 0;
	pthread_mutex_lock(&philo->data->mut_end);
	end = philo->data->end;
	pthread_mutex_unlock(&philo->data->mut_end);
	if (!end)
	{
		pthread_mutex_lock(&philo->data->mut_time);
		pthread_mutex_lock(&philo->data->mut_print);
		time = timer();
	    printf("%ld %s has taken a fork\n", time - philo->data->time, philo->val_c);
    	pthread_mutex_unlock(&philo->data->mut_print);
		pthread_mutex_unlock(&philo->data->mut_time);
	}
}

void    eat(t_philo *philo)
{
    time_t	time;
	int		end;

	end = 0;
	pthread_mutex_lock(&philo->data->mut_end);
	end = philo->data->end;
	pthread_mutex_unlock(&philo->data->mut_end);
	if (!end)
	{
		pthread_mutex_lock(&philo->data->mut_time);
		pthread_mutex_lock(&philo->data->mut_print);
		time = timer();
	    printf("%ld %s is eating\n", time - philo->data->time, philo->val_c);
    	pthread_mutex_unlock(&philo->data->mut_print);
		pthread_mutex_unlock(&philo->data->mut_time);
	}
}

void    sleeping(t_philo *philo)
{
    time_t	time;
	int		end;

	end = 0;
	pthread_mutex_lock(&philo->data->mut_end);
	end = philo->data->end;
	pthread_mutex_unlock(&philo->data->mut_end);
	if (!end)
	{
		pthread_mutex_lock(&philo->data->mut_time);
		pthread_mutex_lock(&philo->data->mut_print);
		time = timer();
	    printf("%ld %s is sleeping\n", time - philo->data->time, philo->val_c);
    	pthread_mutex_unlock(&philo->data->mut_print);
		pthread_mutex_unlock(&philo->data->mut_time);
	}
}

void    thinking(t_philo *philo)
{
    time_t	time;
	int		end;

	end = 0;
	pthread_mutex_lock(&philo->data->mut_end);
	end = philo->data->end;
	pthread_mutex_unlock(&philo->data->mut_end);
	if (!end)
	{
		pthread_mutex_lock(&philo->data->mut_time);
		pthread_mutex_lock(&philo->data->mut_print);
		time = timer();
	    printf("%ld %s is thinking\n", time - philo->data->time,  philo->val_c);
    	pthread_mutex_unlock(&philo->data->mut_print);
		pthread_mutex_unlock(&philo->data->mut_time);
	}
}