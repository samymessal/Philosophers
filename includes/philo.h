/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:51:47 by smessal           #+#    #+#             */
/*   Updated: 2023/03/16 18:29:08 by smessal          ###   ########.fr       */
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
	time_t	ate;
	int		died;
	int		num_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
    pthread_mutex_t fork;
	pthread_mutex_t	mut_ate;
	struct s_data	*data;
	void	*next;
	void	*prev;
}               t_philo;

typedef struct s_data
{
	pthread_mutex_t	mut_print;
	t_philo			*philo_died;
	time_t			t_die;
	// pthread_mutex_t	mut_ate;
	t_philo			*philo;
}				t_data;

/*---------------------ROUTINE-----------------------------------------------*/
void    *routine(void *arg);
void	*start_checker(void *arg);
/*---------------------ACTIONS-----------------------------------------------*/
void    tfork(t_philo *philo);
void    eat(t_philo *philo);
void    sleeping(t_philo *philo);
void    thinking(t_philo *philo);
/*----------------------CHECKER----------------------------------------------*/
int philo_ate(void);
int	calc_eat(struct timeval time, int ate);
int	dies(t_data *data);
/*---------------------UTILS-------------------------------------------------*/

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
time_t	timer(void);
/*---UTILS LIST---*/
void    lst_addback(t_philo **philo, t_philo *new);
t_philo	*lst_new(char **av, int i, t_data *data);
t_philo	*lst_last(t_philo *philo);
/*----UTILS MUTEX-------*/
void	locker(t_philo *philo, t_philo *prev);
void	unlocker(t_philo *philo, t_philo *prev);
/*----UTILS ROUTINE-----*/
void	first_philo(t_philo *philo, t_philo *last);
void	other_philo(t_philo *philo, t_philo *prev);

#endif