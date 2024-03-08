/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:18:27 by mafranco          #+#    #+#             */
/*   Updated: 2024/03/08 20:39:48 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				nb_eat;
	int				fork_1;
	int				fork_2;
	int				times_eat;
	long int		t_die;
	long int		t_eat;
	long int		t_sleep;
	long int		first_time;
	long int		t_last_eat;
	struct s_data	*d;
}		t_philo;

typedef struct s_data
{
	int				nb_phi;
	int				dead_phi;
	int				philo_end;
	int				times_eat;
	long int		t_die;
	long int		t_eat;
	long int		t_sleep;
	long int		first_time;
	t_philo			**philo;
	pthread_t		*thread;
	pthread_t		death;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mut_eating;
	pthread_mutex_t	mut_writing;
	pthread_mutex_t	mut_nb_eat;
	pthread_mutex_t	mut_win;
	pthread_mutex_t	mut_acces_d;
}		t_data;

int			ft_atoi(const char *str);

long int	ft_time(void);

int			init_d(t_data *d, int argc, char **argv);

int			create_mutex(t_data *d);

int			create_philo(t_data *d);

int			create_thread(t_data *d, int i);

void		*philo_action(void *data);

void		philo_write(t_philo *p, char *str);

int			philo_death(t_philo *p);

int			death_check(t_philo *p);

int			finish_check(t_philo *p);

int			one_philo(t_data *d);

int			free_mutex(t_data *d, int nb, int i);

int			free_philo(t_data *d, int i);

#endif
