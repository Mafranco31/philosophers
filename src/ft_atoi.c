/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:04:30 by mafranco          #+#    #+#             */
/*   Updated: 2024/03/08 14:08:08 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	check_nptr(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i])
	{
		if ((nptr[i] < 48 || nptr[i] > 57) && nptr[i] != '-' && nptr[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	resultat;
	int	i;
	int	negative;

	if (check_nptr(nptr) == 1)
		return (-1);
	i = 0;
	negative = 1;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == 32)
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negative *= -1;
		i++;
	}
	resultat = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		resultat = (resultat * 10) + (nptr[i++] - 48);
	if ((resultat * negative) < 0)
		return (-1);
	return (resultat * negative);
}
