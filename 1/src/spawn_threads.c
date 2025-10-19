/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 02:32:42 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/19 17:31:46 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//WOIP
uint32_t	philo_order(uint32_t i, uint32_t max)
{
	uint32_t	middle;

	middle = max / 2;
	if (i < middle)
		return (0);
	else if (i > middle)
		return (2);
}

t_philo	*spawn_threads(t_app app)
{
	t_philo		*philos;
	uint32_t	i;

	philos = malloc(sizeof(t_philo) * app.conf->n);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < app.conf->n)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]))
		{
			free(philos);
			return (NULL);
		}
		i += 2;
	}
	i = 1;
	while (i < app.conf->n)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]))
		{
			free(philos);
			return (NULL);
		}
		i += 2;
	}
	return (philos);
}
