/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:42:21 by mafranco          #+#    #+#             */
/*   Updated: 2024/03/08 19:43:12 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	free_philo(t_data *d, int i)
{
	while (i > 0)
	{
		free(d->philo[i - 1]);
		i--;
	}
	free(d->philo);
	free_mutex(d, 6, d->nb_phi);
	return (1);
}

int	create_philo(t_data *d)
{
	int	i;

	d->philo = (t_philo **)malloc(sizeof(t_philo *) * d->nb_phi);
	if (!d->philo)
		return (free_mutex(d, 6, d->nb_phi));
	i = 0;
	while (i < d->nb_phi)
	{
		d->philo[i] = malloc(sizeof(t_philo));
		if (!d->philo[i])
			return (free_philo(d, i));
		d->philo[i]->nb_eat = 0;
		d->philo[i]->fork_1 = i;
		d->philo[i]->fork_2 = (i + 1) % d->nb_phi;
		d->philo[i]->t_last_eat = d->first_time;
		d->philo[i]->first_time = d->first_time;
		d->philo[i]->d = d;
		d->philo[i]->times_eat = d->times_eat;
		d->philo[i]->t_die = d->t_die;
		d->philo[i]->t_eat = d->t_eat;
		d->philo[i]->t_sleep = d->t_sleep;
		i++;
	}
	return (0);
}
