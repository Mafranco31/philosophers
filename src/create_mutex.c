/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:09:16 by mafranco          #+#    #+#             */
/*   Updated: 2024/03/08 19:29:11 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	free_mutex(t_data *d, int nb, int i)
{
	if (nb > 1)
		pthread_mutex_destroy(&d->mut_eating);
	if (nb > 2)
		pthread_mutex_destroy(&d->mut_writing);
	if (nb > 3)
		pthread_mutex_destroy(&d->mut_win);
	if (nb > 4)
		pthread_mutex_destroy(&d->mut_acces_d);
	if (nb > 5)
	{
		pthread_mutex_destroy(&d->mut_nb_eat);
		while (i > 0)
		{
			pthread_mutex_destroy(&d->forks[i - 1]);
			i--;
		}
	}
	free(d->forks);
	return (1);
}

int	create_mutex(t_data *d)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&d->mut_eating, NULL))
		return (free_mutex(d, 1, i));
	if (pthread_mutex_init(&d->mut_writing, NULL))
		return (free_mutex(d, 2, i));
	if (pthread_mutex_init(&d->mut_win, NULL))
		return (free_mutex(d, 3, i));
	if (pthread_mutex_init(&d->mut_acces_d, NULL))
		return (free_mutex(d, 4, i));
	if (pthread_mutex_init(&d->mut_nb_eat, NULL))
		return (free_mutex(d, 5, i));
	d->forks = malloc(sizeof(pthread_mutex_t) * d->nb_phi);
	if (!d->forks)
		return (free_mutex(d, 6, i));
	while (i < d->nb_phi)
	{
		if (pthread_mutex_init(&d->forks[i], NULL))
			return (free_mutex(d, 6, i));
		i++;
	}
	return (0);
}
