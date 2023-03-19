/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:51:47 by smessal           #+#    #+#             */
/*   Updated: 2023/03/19 14:44:09 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

/*---------------------STRUCT------------------------------------------------*/

typedef struct s_thread
{
	int				index;
	char			*val_c;
	time_t			ate;
	int				died;
	long			count;
	long			times_eat;
	long			num_philo;
	time_t			t_die;
	time_t			t_eat;
	time_t			t_sleep;
	pthread_mutex_t	mut_count;
	pthread_mutex_t	fork;
	pthread_mutex_t	mut_ate;
	struct s_data	*data;
	void			*next;
	void			*prev;
}				t_philo;

typedef struct s_data
{
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_end;
	pthread_mutex_t	mut_time;
	int				end;
	long			num_philo;
	pthread_t		*philosophers;
	time_t			time;
	time_t			t_die;
	long			eats_time;
	t_philo			*philo_died;
	t_philo			*philo;
}				t_data;

/*--------------------INIT-----------------------------------------------*/
t_philo	*init_philo(char **av, t_data *data);
t_data	*init_data(void);
void	init_data2(char **av, t_data **data, t_philo *philo);
/*---------------------ROUTINE-----------------------------------------------*/
void	*routine(void *arg);
void	*start_checker(void *arg);
/*---------------------ACTIONS-----------------------------------------------*/
void	tfork(t_philo *philo);
void	eat(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
/*----------------------CHECKER----------------------------------------------*/
int		philo_ate(void);
int		calc_eat(struct timeval time, int ate);
int		dies(t_data *data);
/*---------------------UTILS-------------------------------------------------*/

long	ft_atol(char *str);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
time_t	timer(void);
int		ft_strlen(const char *str);
int		numlen(long long int num);
int		is_numeric(char *str);
int		usleep_me(time_t rest);
/*---UTILS LIST---*/
void	lst_addback(t_philo **philo, t_philo *new);
t_philo	*lst_new(char **av, int i, t_data *data);
t_philo	*lst_last(t_philo *philo);
/*----UTILS MUTEX-------*/
void	locker(t_philo *philo, t_philo *prev);
void	unlocker(t_philo *philo, t_philo *prev);
/*----UTILS ROUTINE-----*/
void	first_philo(t_philo *philo, t_philo *last);
void	one_philo(t_philo *philo);
void	other_philo(t_philo *philo, t_philo *prev);
void	three_philos(t_philo *philo);
void	index_1(t_philo *philo);
void	index_2(t_philo *philo);
void	index_3(t_philo *philo);

/*---------------------FREE-----------------------------------------------*/
void	free_data(t_data *data);
void	free_philo(t_philo *philo);
void	check_locks(t_data *data);
void	free_philos(pthread_t	*philosophers);
void	free_all(t_data *data, pthread_t *philosophers);
#endif