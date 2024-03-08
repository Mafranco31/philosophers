/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:04:37 by mafranco          #+#    #+#             */
/*   Updated: 2024/03/08 19:24:25 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	free_thread(t_data *d)
{
	free(d->thread);
	return (free_philo(d, d->nb_phi));
}

int	create_thread(t_data *d, int i)
{
	d->thread = malloc(sizeof(pthread_t) * d->nb_phi);
	if (!d->thread)
		return (free_philo(d, d->nb_phi));
	while (i < d->nb_phi)
	{
		if (pthread_create(&d->thread[i], NULL, philo_action, d->philo[i]))
			return (free_thread(d));
		i++;
	}
	i = 0;
	while (i < d->nb_phi)
	{
		if (pthread_join(d->thread[i], NULL))
			return (free_thread(d));
		i++;
	}
	free(d->thread);
	return (0);
}
