/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:05:39 by mafranco          #+#    #+#             */
/*   Updated: 2023/11/13 21:20:37 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	errormessage(t_data *d, t_philo *p)
{
	free(p);
	free(d);
	printf("\nWrong arguments: need\n .[number_of_philosophers]\n");
	printf(" .[time_to_die]\n .[time_to_eat]\n .[time_to_sleep]\n");
	printf(" .[number_of_times_each_philosopher_must_eat] (optional)\n");
	printf("\nValues should be integer and time is in milliseconds\n\n");
	return (-1);
}

int	initarg(t_data *d, int argc, char **argv)
{
	d->win = 0;
	d->death = 0;
	d->nb_phi = getdata(argv[1]);
	d->t_die = getdata(argv[2]) * 1000;
	d->t_eat = getdata(argv[3]) * 1000;
	d->t_sleep = getdata(argv[4]) * 1000;
	if (argc == 5)
		d->times_eat = -1;
	else
		d->times_eat = getdata(argv[5]);
	if (d->nb_phi > 1 && d->t_die >= 0 && d->t_eat >= 0 && d->t_sleep >= 0
		&& (argc == 5 || (argc == 6 && d->times_eat > 0)))
		return (0);
	return (-1);
}

int	freephilo(t_philo *p, int i, t_data *d)
{
	t_philo	*temp;

	free(d);
	while (i > 0)
	{
		temp = p;
		p = p->next;
		free(temp);
		i--;
	}
	return (-1);
}

int	initphilo(t_data *d, t_philo *p, int i)
{
	t_philo	*first;

	first = p;
	while (i < d->nb_phi)
	{
		p->win = 0;
		p->death = 0;
		p->num = i;
		p->nb_eat = 0;
		p->d = d;
		p->last_eat = ft_time();
		p->next = (t_philo *)malloc(sizeof(t_philo));
		if (!p->next)
			return (freephilo(first, i, d));
		p = p->next;
		i++;
	}
	p->win = 0;
	p->death = 0;
	p->num = i;
	p->nb_eat = 0;
	p->d = d;
	p->next = first;
	p->last_eat = ft_time();
	return (0);
}

int	initdata(int argc, char **argv, t_philo *p)
{
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	if (!d)
	{
		free(p);
		return (-1);
	}
	if (argc != 5 && argc != 6)
		return (errormessage(d, p));
	if (initarg(d, argc, argv) == -1)
		return (errormessage(d, p));
	if (initphilo(d, p, 1) == -1)
		return (errormessage(d, p));
	return (0);
}
