/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:57 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/30 13:08:10 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
 */
void	*philo_routine(void *arg)
{
	t_philo		*self;
	int			stage;

	stage = 0;
	self = (t_philo *) arg;
	while ((self->meals < self->app->conf.limit) && self->life)
	{
		stage = life_cycle(self, stage);
		self->meals++;
	}
	return (NULL);
}

/*
 * routine for the monitor thread
 * it constantly checks the last time each philosopher ate, if it was
 * longer than ttd ms ago, changes it's life value to 0
 */
void	*monitor_routine(void *arg)
{
	uint32_t	i;
	t_philo		*philos;
	t_app		*app;

	philos = (t_philo *)arg;
	app = philos[0].app;
	i = 0;
	while (i < app->conf.n)
	{
		hunger(*app, philos[i].last_meal, &philos[i].life, (int)i);
		i++;
	}
	return (NULL);
}
