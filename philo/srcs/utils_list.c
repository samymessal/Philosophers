/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:04:59 by smessal           #+#    #+#             */
/*   Updated: 2023/03/17 14:49:13 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    lst_addback(t_philo **philo, t_philo *new)
{
    t_philo	*temp;

    temp = *philo;
    if (!(*philo))
    {
        *philo = new;
        return ;
    }
    while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

t_philo	*lst_new(char **av, int i, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->index = i + 1;
	philo->ate = 0;
	philo->died = 0;
	philo->count = 0;
	philo->val_c = ft_itoa(i + 1);
	philo->num_philo = ft_atol(av[1]);
	philo->t_die = ft_atol(av[2]) * 1000;
	philo->t_eat = ft_atol(av[3]) * 1000;
	philo->t_sleep = ft_atol(av[4]) * 1000;
	philo->data = data;
	pthread_mutex_init(&philo->fork, NULL);
	pthread_mutex_init(&philo->mut_count, NULL);
	pthread_mutex_init(&philo->mut_ate, NULL);
	philo->next = NULL;
	philo->prev = NULL;
	return (philo);
}

t_philo	*lst_last(t_philo *philo)
{
	t_philo	*temp;

	temp = philo;
	if (!temp)
		return (NULL);
	while (temp && temp->next)
		temp = temp->next;
	return (temp);
}
