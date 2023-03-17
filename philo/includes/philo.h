/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:51:47 by smessal           #+#    #+#             */
/*   Updated: 2023/03/18 00:42:09 by smessal          ###   ########.fr       */
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
#include <limits.h>

/*---------------------STRUCT------------------------------------------------*/

typedef struct s_thread
{
    int     		index;
    char    		*val_c;
	time_t			ate;
	int				died;
	int				count;
	long			num_philo;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	pthread_mutex_t	mut_count;
    pthread_mutex_t fork;
	pthread_mutex_t	mut_ate;
	struct s_data	*data;
	void			*next;
	void			*prev;
}               t_philo;

typedef struct s_data
{
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_end;
	pthread_mutex_t	mut_time;
	int				end;
	pthread_t		*philosophers;
	time_t			time;
	time_t			t_die;
	int				eats_time;
	t_philo			*philo_died;
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

long	ft_atol(char *str);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
time_t	timer(void);
int		ft_strlen(const char *str);
int		numlen(long long int num);
int		is_numeric(char *str);
/*---UTILS LIST---*/
void    lst_addback(t_philo **philo, t_philo *new);
t_philo	*lst_new(char **av, int i, t_data *data);
t_philo	*lst_last(t_philo *philo);
/*----UTILS MUTEX-------*/
void	locker(t_philo *philo, t_philo *prev);
void	unlocker(t_philo *philo, t_philo *prev);
/*----UTILS ROUTINE-----*/
void	first_philo(t_philo *philo, t_philo *last);
void	one_philo(t_philo *philo);
void	other_philo(t_philo *philo, t_philo *prev);
/*---------------------FREE-----------------------------------------------*/
void	free_data(t_data *data);
void	free_philo(t_philo *philo);
void	check_locks(t_data *data);
void	free_philos(pthread_t	*philosophers);
#endif