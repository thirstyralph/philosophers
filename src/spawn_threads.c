/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:26:24 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/15 21:09:00 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	set_philo(uint32_t i, t_philo *philo, t_app *app)
{
	philo->id = i;
	philo->app = app;
	pthread_mutex_init(&philo->last_meal.lock, NULL);
	pthread_mutex_init(&philo->full.lock, NULL);
	pthread_mutex_lock(&philo->last_meal.lock);
	philo->meals = 0;
	pthread_mutex_unlock(&philo->last_meal.lock);
	pthread_mutex_lock(&philo->last_meal.lock);
	philo->last_meal.time = app->start;
	pthread_mutex_unlock(&philo->last_meal.lock);
	pthread_mutex_lock(&philo->full.lock);
	philo->full.state = 0;
	pthread_mutex_unlock(&philo->full.lock);
	if (i == app->conf->n - 1)
	{
		philo->fork_r = &app->forks[i];
		philo->fork_l = &app->forks[(i + 1) % app->conf->n];
	}
	else
	{
		philo->fork_l = &app->forks[i];
		philo->fork_r = &app->forks[(i + 1) % app->conf->n];
	}
}

/*
 * reates a thread array and initializes all of it's components
*/
t_philo	*spawn_threads(t_app *app)
{
	t_philo			*r;
	uint32_t		i;

	i = 0;
	r = malloc(sizeof(t_philo) * (app->conf->n));
	if (!r)
		return (NULL);
	while (i < app->conf->n)
	{
		set_philo(i, &r[i], app);
		if (pthread_create(&r[i].thread, NULL, philo_routine, &r[i]) != 0)
		{
			free(r);
			return (NULL);
		}
		i++;
	}
	return (r);
}
