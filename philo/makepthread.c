/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makepthread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:33:32 by mafranco          #+#    #+#             */
/*   Updated: 2023/12/20 19:29:28 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	freemutex(t_philo *p, int i, int nb)
{
	while (i > 0)
	{
		pthread_mutex_destroy(&p->fork);
		p = p->next;
		i--;
	}
	if (nb >= 1)
		pthread_mutex_destroy(&p->d->mut_eating);
	if (nb >= 2)
		pthread_mutex_destroy(&p->d->mut_writing);
	if (nb >= 3)
		pthread_mutex_destroy(&p->d->mut_win);
	return (-1);
}

int	makemutex(t_philo *p)
{
	int		i;
	t_philo	*first;

	first = p;
	i = 0;
	while (i < p->d->nb_phi)
	{
		if (pthread_mutex_init(&p->fork, NULL))
			return (freemutex(first, i, 0));
		p = p->next;
		i++;
	}
	if (pthread_mutex_init(&p->d->mut_eating, NULL))
		return (freemutex(first, i, 0));
	if (pthread_mutex_init(&p->d->mut_writing, NULL))
		return (freemutex(first, i, 1));
	if (pthread_mutex_init(&p->d->mut_win, NULL))
		return (freemutex(first, i, 2));
	return (0);
}

int	makepthread(t_philo *p, int i)
{
	t_philo	*first;

	first = p;
	p->d->first_time = ft_time();
	while (i < p->d->nb_phi)
	{
		if (pthread_create(&p->thread, NULL, philo_action, p))
			return (freemutex(first, p->d->nb_phi, 3));
		p = p->next;
		i++;
	}
	i = 0;
	while (i < p->d->nb_phi)
	{
		if (pthread_join(p->thread, NULL))
			return (freemutex(first, p->d->nb_phi, 3));
		p = p->next;
		i++;
	}
	freemutex(p, p->d->nb_phi, 3);
	return (0);
}

int	ft_pthread_make(t_philo *p)
{
	if (makemutex(p) == -1)
		return (-1);
	if (makepthread(p, 0) == -1)
		return (-1);
	return (0);
}
