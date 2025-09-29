/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:57 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/29 14:20:02 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
 *	casts argument to t_app 
 * eat
 * 		take(mutex_lock) two forks
 * 		eat(sleep for x time)
 * 		drop (mutex_unlock) the forks)
 * sleep
 * think
 */
void	*_philo_routine(void *arg)
{
	t_philo		*self;

	self = (t_philo *) arg;
	printf("meals = %u\n limit = %u\n", self->meals, self->app->conf.limit);
	while ((self->meals < self->app->conf.limit))
	{
		safe_print(self->id, 0, self->app);
		safe_print(self->id, 1, self->app);
		safe_print(self->id, 2, self->app);
		safe_print(self->id, 3, self->app);
		safe_print(self->id, 4, self->app);
		self->meals++;
	}
	return (NULL);
}
