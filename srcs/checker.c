/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:39:50 by smessal           #+#    #+#             */
/*   Updated: 2023/03/13 23:28:11 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*-----Demander pour les free struct timeval------*/

int philo_ate(void)
{
    struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec);
}

int	calc_eat(struct timeval time, int ate)
{
	int	i;
	int	j;
	int	result;

	i = time.tv_usec;
	j = ate;
	result = 0;
	if (j < i)
	{
		result = i - j;
		result = 1000000 - result;
	}
	else
		result = j - i;
	return (result);
}

int	dies(t_data *data)
{
	t_philo			*philo;
	struct timeval	time;

	philo = data->philo;
	while (1 && philo)
	{
		gettimeofday(&time, NULL);
        pthread_mutex_lock(&philo->mut_ate);
		if (calc_eat(time, philo->ate) >= philo->t_die)
		{
            pthread_mutex_unlock(&philo->mut_ate);
			return (1);
        }
        pthread_mutex_unlock(&philo->mut_ate);
        philo = philo->next;
        if (!philo)
            philo = data->philo;
	}
	return (0);
}
