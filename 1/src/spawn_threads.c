/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 02:32:42 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/21 20:45:19 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

uint32_t	philo_order(uint32_t i, uint32_t max)
{
	uint32_t	middle;

	middle = max / 2;
	if (i < middle)
		return (i * 2);
	else if (i == middle)
		return (1);
	else
		return ((i - middle) + (i - 1 - middle));
}

t_philo	*spawn_threads(t_app *app)
{
	t_philo		*philos;
	uint32_t	i;

	philos = malloc(sizeof(t_philo) * app->conf->n);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < app->conf->n)
	{
		if (pthread_create(&philos[philo_order(i, app->conf->n)].thread,
				NULL, philo_routine, &philos[i]))
		{
			free(philos);
			return (NULL);
		}
		i++;
	}
	return (philos);
}

void	join_philos(t_philo *philos)
{
	uint32_t	i;

	i = 0;
	while (i < philos[0].conf->n)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}
