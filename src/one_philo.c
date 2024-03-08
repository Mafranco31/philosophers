/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:17:26 by mafranco          #+#    #+#             */
/*   Updated: 2024/03/08 20:23:41 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	one_philo(t_data *d)
{
	printf("0 1 \033[33mis thinking\033[0m\n");
	usleep(d->t_die);
	printf("%ld 1 \033[31mdied\033[0m\n", d->t_die / 1000);
	return (0);
}
