/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:12:02 by mafranco          #+#    #+#             */
/*   Updated: 2024/03/08 20:39:13 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	philo_death(t_philo *p)
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
}

int	finish_check(t_philo *p)
{
	int	i;

	if (p->times_eat < 0)
		return (0);
	pthread_mutex_lock(&p->d->mut_win);
	if (p->d->philo_end == 0)
		i = 1;
	else
		i = 0;
	pthread_mutex_unlock(&p->d->mut_win);
	return (i);
}

int	death_check(t_philo *p)
{
	int	i;

	pthread_mutex_lock(&p->d->mut_acces_d);
	if (p->d->dead_phi == 1)
		i = 1;
	else
		i = 0;
	pthread_mutex_unlock(&p->d->mut_acces_d);
	return (i);
}
