/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:23:33 by mafranco          #+#    #+#             */
/*   Updated: 2023/11/13 00:23:59 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	freeall(t_philo *p)
{
	int		i;
	t_philo	*temp;

	i = p->d->nb_phi;
	free(p->d);
	while (i > 0)
	{
		temp = p;
		p = p->next;
		free(temp);
		i--;
	}
}

void	philo_sleep(long time_to_wait, long first_time)
{
	long	i;

	i = ft_time();
	if (i == -1)
	{
		while (i == -1)
			i = ft_time();
	}		
	while (i - first_time <= time_to_wait)
	{
		usleep(10);
		i = ft_time();
	}
}

int	ft_atoi(const char *ptr)
{
	long long	res;
	int			i;
	int			neg;

	i = 0;
	neg = 1;
	while (ptr[i] == '\t' || ptr[i] == '\n' || ptr[i] == '\v'
		|| ptr[i] == '\f' || ptr[i] == '\r' || ptr[i] == 32)
		i++;
	while (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			neg *= -1;
		i++;
	}
	res = 0;
	while (ptr[i])
	{
		if (ptr[i] > '9' || ptr[i] < '0')
			return (-1);
		res = (res * 10) + (ptr[i] - 48);
		i++;
	}
	return (res * neg);
}

long	ft_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return (time.tv_sec * 1000000 + time.tv_usec);
}
