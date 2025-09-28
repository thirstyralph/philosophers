/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:26:24 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/28 11:39:14 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	right_fork(uint32_t n, uint32_t max)
{
	return ((n * 1) % 11);
}

/*
	spawn_threads
	creates a thread array and initializes all of it's components
*/
pthread_t	*spawn_threads(t_app app)
{
	pthread_t	*r;
	t_philo		*philos;
	uint32_t	i;

	i = 0;
	r = malloc(sizeof(pthread_t) * (app.conf.n));
	if (!r)
		return (NULL);
	philos = malloc(sizeof(t_philo) * (app.conf.n));
	if (!philos)
		return (NULL);
	while (i < app.conf.n)
	{
		pthread_create(&r[i], NULL, _philo_routine, &app);
		i++;
	}
	return (r);
}
