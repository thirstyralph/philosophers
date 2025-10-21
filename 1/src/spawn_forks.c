/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 01:41:56 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/21 19:07:25 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
 * pthread_mutex_t *spawn_forks
 * allocs and inits an array of mutexes to be used as forks
 * returns:
 * on success: pthread_mutex_t array;
 * on failure: NULL;
 */
pthread_mutex_t	*spawn_forks(uint32_t n)
{
	pthread_mutex_t	*forks;
	uint32_t		i;

	forks = malloc(sizeof(pthread_mutex_t) * n);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (!pthread_mutex_init(&forks[i], NULL))
		{
			while (i < 0)
			{
				pthread_mutex_destroy(&forks[i]);
				i--;
			}
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

void	destroy_and_free_forks(pthread_mutex_t *forks, uint32_t n)
{
	uint32_t	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
}
