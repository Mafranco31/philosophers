/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:30:30 by mafranco          #+#    #+#             */
/*   Updated: 2023/11/13 21:19:40 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data
{
	int				win;
	int				death;
	int				times_eat;
	long			nb_phi;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	long			first_time;
	pthread_t		diethread;
	pthread_mutex_t	mut_eating;
	pthread_mutex_t	mut_writing;
	pthread_mutex_t	mut_win;
}		t_data;

typedef struct s_philo
{
	int				win;
	int				death;
	int				num;
	int				nb_eat;
	long			last_eat;
	void			*before;
	void			*next;
	pthread_t		thread;
	pthread_mutex_t	fork;
	t_data			*d;
}		t_philo;

int		initdata(int argc, char **argv, t_philo *p);

long	getdata(const char *ptr);

long	ft_time(void);

void	freeall(t_philo *p);

int		ft_pthread_make(t_philo *p);

void	*philo_action(void *philo);

void	*check_death(void *philo);

void	philo_sleep(long time_to_wait, long first_time);

#endif
