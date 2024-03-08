/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:18:27 by mafranco          #+#    #+#             */
/*   Updated: 2024/03/08 20:22:06 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	d;

	if (init_d(&d, argc, argv))
		return (1);
	if (d.nb_phi == 1)
		return (one_philo(&d));
	if (create_mutex(&d))
		return (1);
	if (create_philo(&d))
		return (1);
	if (create_thread(&d, 0))
		return (1);
	free_philo(&d, d.nb_phi);
	return (0);
}
