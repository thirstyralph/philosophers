/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:27:27 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/08 18:16:03 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*self;
	int		stage;

	stage = 0;
	self = (t_philo *) arg;
	if (self->app->conf->limit == 0)
	{
		while (get_life(&(self->app->life)))
		{
			stage = life_cycle(self, stage);
			self->meals++;
		}
	}
	else
	{
		while ((self->meals < self->app->conf->limit) && &(self->app->life))
		{
			stage = life_cycle(self, stage);
			self->meals++;
		}
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
			if (hunger(*app, philos[i].last_meal))
			{
				safe_print(i, 4, app);
				pthread_mutex_lock(&(app->life.lock));
				app->life.state = 0;
				pthread_mutex_unlock(&(app->life.lock));
			}
			i++;
			usleep(1000);
		}
	}
	return (NULL);
}
