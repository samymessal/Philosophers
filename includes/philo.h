/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:51:47 by smessal           #+#    #+#             */
/*   Updated: 2023/03/10 17:37:23 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

/*---------------------STRUCT------------------------------------------------*/

typedef struct s_thread
{
    int     index;
    char    *val_c;
    pthread_mutex_t mutex;
}               t_thread;

typedef struct s_data
{
	int			index;
	int			num_philo;
	pthread_mutex_t	mut_ind;
	t_thread	*mutex;
}				t_data;

/*---------------------UTILS-------------------------------------------------*/

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);

#endif