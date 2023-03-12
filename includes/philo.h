/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:51:47 by smessal           #+#    #+#             */
/*   Updated: 2023/03/12 15:45:00 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>

/*---------------------STRUCT------------------------------------------------*/

typedef struct s_thread
{
    int     index;
    char    *val_c;
	int		ate;
	int		died;
    pthread_mutex_t mutex;
}               t_philo;

typedef struct s_data
{
	int			index;
	int			num_philo;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	pthread_mutex_t	mut_ind;
	t_philo	*mutex;
}				t_data;

/*---------------------ROUTINE-----------------------------------------------*/
void    *start_impair(void *arg);
void    *start_pair(void *arg);
/*---------------------ACTIONS-----------------------------------------------*/
void    tfork(t_philo philo);
void    eat(t_philo philo);
void    sleeping(t_philo philo);
void    thinking(t_philo philo);
/*---------------------UTILS-------------------------------------------------*/

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);

#endif