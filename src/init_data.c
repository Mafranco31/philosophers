/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:37:49 by mafranco          #+#    #+#             */
/*   Updated: 2024/03/08 20:17:39 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	error_msg_init_d(void)
{
	printf("\nWrong arguments: need\n .[number_of_philosophers]\n");
	printf(" .[time_to_die]\n .[time_to_eat]\n .[time_to_sleep]\n");
	printf(" .[number_of_times_each_philosopher_must_eat] (optional)\n");
	printf("\nValues should be unsigned integer and time is in ms\n\n");
	return (1);
}

long int	ft_time(void)
{
	struct timeval	tv;
	long long int	t;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	t = (tv.tv_sec * 1000000 + tv.tv_usec) % 1000000000;
	return (t);
}

int	init_d(t_data *d, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (error_msg_init_d());
	d->nb_phi = ft_atoi(argv[1]);
	d->t_die = ft_atoi(argv[2]) * 1000;
	d->t_eat = ft_atoi(argv[3]) * 1000;
	d->t_sleep = ft_atoi(argv[4]) * 1000;
	d->first_time = ft_time();
	if (d->first_time == -1)
		return (1);
	if (argc == 5)
		d->times_eat = -2;
	else
		d->times_eat = ft_atoi(argv[5]);
	if (d->nb_phi == -1 || d->t_die == -1000 || d->t_eat == -1000
		|| d->t_sleep == -1000 || d->times_eat == -1)
		return (error_msg_init_d());
	d->dead_phi = 0;
	d->philo_end = d->nb_phi;
	return (0);
}
