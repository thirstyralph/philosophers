/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:27:27 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/02 17:00:46 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*self;
	int		stage;

	stage = 0;
	self = (t_philo *) arg;
	if (self->app->conf.limit == 0)
	{
		while (self->app->life == 1)
		{
			stage = life_cycle(self, stage);
			self->meals++;
		}
	}
	else
	{
		while ((self->meals < self->app->conf.limit) && self->app->life == 1)
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
	while (app->life)
	{
		i = 0;
		while (i < app->conf.n && app->life == 1)
		{
			if (hunger(*app, philos[i].last_meal))
			{
				safe_print(i, 4, app);
				app->life = 0;
			}
			i++;
		}
	}
	return (NULL);
}
