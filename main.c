/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:57:30 by mafranco          #+#    #+#             */
/*   Updated: 2023/11/13 00:30:48 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*p;

	p = (t_philo *)malloc(sizeof(t_philo));
	if (!p)
		return (0);
	if (initdata(argc, argv, p) == -1)
		return (0);
	ft_pthread_make(p);
	freeall(p);
	return (0);
}
