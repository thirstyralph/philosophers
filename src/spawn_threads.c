/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:21:29 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/24 13:21:32 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	assign_forks(t_philo *philo, uint32_t id, uint32_t n,
		pthread_mutex_t *forks)
{
	if (id == n - 1)
	{
		philo->fork_l = &forks[id];
		philo->fork_r = &forks[(id + 1) % n];
	}
	else
	{
		philo->fork_l = &forks[(id + 1) % n];
		philo->fork_r = &forks[id];
	}
}

int	init_philo(t_philo *philos, uint32_t pos, t_app *app)
{
	philos[pos].last_meal = app->start;
	philos[pos].conf = app->conf;
	philos[pos].app = app;
	philos[pos].meals = 0;
	philos[pos].id = pos;
	if (pthread_mutex_init(&philos[pos].meals_lock, NULL))
		return (1);
	if (app->conf->n > 1)
	{
		if (pthread_create(&philos[pos].thread, NULL, philo_routine,
				(void *)&philos[pos]))
			return (1);
	}
	else
	{
		if (pthread_create(&philos[pos].thread, NULL, lonely_routine,
				(void *)&philos[pos]))
			return (1);
	}
	return (0);
}

uint32_t	philo_order(uint32_t i, uint32_t max)
{
	uint32_t	half;

	half = (max + 1) / 2;
	if (i < half)
		return (i * 2);
	else
		return ((i - half) * 2 + 1);
}

t_philo	*spawn_threads(t_app *app, pthread_mutex_t *forks)
{
	t_philo		*philos;
	uint32_t	pos;
	uint32_t	i;

	philos = malloc(sizeof(t_philo) * app->conf->n);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < app->conf->n)
	{
		pos = philo_order(i, app->conf->n);
		if (app->conf->n > 1)
			assign_forks(&philos[pos], pos, app->conf->n, forks);
		if (init_philo(philos, pos, app))
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
	uint32_t	n;

	i = 0;
	n = philos[0].conf->n;
	while (i < n)
	{
		pthread_join(philos[i].thread, NULL);
		pthread_mutex_destroy(&philos[i].meals_lock);
		i++;
	}
}
