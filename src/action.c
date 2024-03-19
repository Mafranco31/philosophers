/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:57:52 by mafranco          #+#    #+#             */
/*   Updated: 2024/03/19 09:39:24 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//static int	philo_death(t_philo *p);

static void	philo_spend_time(long time_to_wait, long first_time)
{
	long	i;

	i = ft_time();
	while (i - first_time <= time_to_wait)
	{
		usleep(200);
		i = ft_time();
	}	
}

void	philo_write(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->d->mut_writing);
	if (!death_check(p) && !finish_check(p))
	{
		printf("%ld ", (ft_time() - p->first_time) / 1000);
		printf("%d %s\n", p->fork_1 + 1, str);
	}
	pthread_mutex_unlock(&p->d->mut_writing);
}

static void	philo_eat_2(t_philo *p)
{
	if (p->times_eat > 0 && p->nb_eat == p->times_eat)
	{
		pthread_mutex_lock(&p->d->mut_nb_eat);
		p->d->philo_end -= 1;
		pthread_mutex_unlock(&p->d->mut_nb_eat);
	}
	if (!death_check(p))
		philo_spend_time(p->t_eat, p->t_last_eat);
	pthread_mutex_unlock(&p->d->forks[p->fork_1]);
	pthread_mutex_unlock(&p->d->forks[p->fork_2]);
}

static void	philo_eat(t_philo *p)
{
	pthread_mutex_lock(&p->d->forks[p->fork_1]);
	if (philo_death(p))
	{
		pthread_mutex_unlock(&p->d->forks[p->fork_1]);
		return ;
	}
	philo_write(p, "\033[36mhas taken a fork\033[0m");
	pthread_mutex_lock(&p->d->forks[p->fork_2]);
	if (philo_death(p))
	{
		pthread_mutex_unlock(&p->d->forks[p->fork_1]);
		pthread_mutex_unlock(&p->d->forks[p->fork_2]);
		return ;
	}
	philo_write(p, "\033[36mhas taken a fork\033[0m");
	philo_write(p, "\033[32mis eating\033[0m");
	p->t_last_eat = ft_time();
	p->nb_eat += 1;
	philo_eat_2(p);
}
/*
static int	philo_death(t_philo *p)
{
	if (ft_time() - p->t_last_eat > p->t_die)
	{
		philo_write(p, "\033[31mdied\033[0m");
		pthread_mutex_lock(&p->d->mut_acces_d);
		p->d->dead_phi = 1;
		pthread_mutex_unlock(&p->d->mut_acces_d);
		return (1);
	}
	return (0);
}*/

void	*philo_action(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->fork_1 % 2 == 0)
		usleep(150);
	while (!death_check(p) && !finish_check(p))
	{
		if (philo_death(p))
			return (NULL);
		philo_write(p, "\033[33mis thinking\033[0m");
		if (philo_death(p))
			return (NULL);
		philo_eat(p);
		if (philo_death(p))
			return (NULL);
		philo_write(p, "\033[35mis sleeping\033[0m");
		if (!death_check(p) && !finish_check(p))
			philo_spend_time(p->t_sleep, p->t_last_eat + p->t_eat);
	}
	return (NULL);
}
