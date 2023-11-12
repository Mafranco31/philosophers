/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:09:51 by mafranco          #+#    #+#             */
/*   Updated: 2023/11/13 00:31:07 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_write(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->d->mut_writing);
	if (p->d->death == 0)
	{
		printf("%ld ", (ft_time() - p->d->first_time) / 1000);
		printf("%d %s\n", p->num, str);
	}
	pthread_mutex_unlock(&p->d->mut_writing);
}

void	philo_eat(t_philo *p, t_philo *next)
{
	pthread_mutex_lock(&next->fork);
	philo_write(p, "has taken a fork");
	pthread_mutex_lock(&p->fork);
	philo_write(p, "has taken a fork");
	pthread_mutex_lock(&p->d->mut_eating);
	philo_write(p, "is eating");
	p->last_eat = ft_time();
	pthread_mutex_unlock(&p->d->mut_eating);
	philo_sleep(p->d->t_eat, p->last_eat);
	p->nb_eat++;
	pthread_mutex_unlock(&next->fork);
	pthread_mutex_unlock(&p->fork);
}

void	philo_end_eat(t_philo *p)
{
	philo_write(p, "is sleeping");
	philo_sleep(p->d->t_sleep, p->last_eat + p->d->t_eat);
	philo_write(p, "is thinking");
}

void	*philo_action(void *philo)
{
	t_philo	*p;
	t_philo	*next;

	p = (t_philo *)philo;
	next = p->next;
	if (p->num % 2 == 0)
		usleep(1000);
	while (p->d->death == 0 && p->win == 0)
	{
		if (ft_time() - p->last_eat >= p->d->t_die)
		{
			p->death = 1;
			philo_write(p, "is died");
			return (NULL);
		}
		else
			philo_eat(p, next);
		if ((p->d->times_eat > 0 && p->nb_eat >= p->d->times_eat))
			p->win = 1;
		else
			philo_end_eat(p);
	}
	return (NULL);
}

void	*check_death(void *philo)
{
	t_philo	*p;
	int		die;
	int		win;
	int		nb;

	p = (t_philo *)philo;
	die = 0;
	win = 0;
	nb = p->d->nb_phi;
	while (die == 0 && (win < nb))
	{
		if (p->death == 1)
			die = 1;
		if (p->win == 1)
			win++;
		p = p->next;
	}
	return (NULL);
}
