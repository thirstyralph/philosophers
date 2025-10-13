/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <ranavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:27:27 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/13 18:29:50 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*self;
	int		stage;

	stage = 0;
	self = (t_philo *) arg;
	while (get_life(&(self->app->life)))
	{
		if (self->meals >= self->app->conf->limit && !is_full(&self->full))
		{
			pthread_mutex_lock(&self->full.lock);
			self->full.state = 1;
			pthread_mutex_unlock(&self->full.lock);
		}
		stage = life_cycle(self, stage);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	uint32_t		i;
	t_philo			*philos;
	t_app			*app;

	philos = (t_philo *)arg;
	app = philos[0].app;
	while (get_life(&(app->life)))
	{
		i = 0;
		while ((i < (*app).conf->n) && get_life(&(app->life)))
		{
			if (hunger(app, &philos[i].last_meal) && get_life(&(app->life)))
			{
				safe_print(i, 4, app);
				pthread_mutex_lock(&(app->life.lock));
				app->life.state = 0;
				pthread_mutex_unlock(&(app->life.lock));
			}
			if (app->conf->limit != 0 && check_all_full(philos)
				&& get_life(&(app->life)))
			{
				pthread_mutex_lock(&(app->life.lock));
				app->life.state = 0;
				pthread_mutex_unlock(&(app->life.lock));
			}
			i++;
		}
	}
	return (NULL);
}
