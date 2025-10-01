/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:24:47 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/01 17:18:05 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_fork(t_app *app, uint32_t id, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	safe_print(id, 0, app);
}

void	drop_fork(pthread_mutex_t *fork)
{
	pthread_mutex_unlock(fork);
}

/*
 * Function: eat
 * every philospher takes two forks, the last one takes the left one 
 * then the right one, every other one does it the other way around.
 * the forks get locked
 * last_meal gets set to current time
 * active sleep during tts miliseconds
 * PROBLEM:
 * the philosopher may die while waiting for the fork  to be unlocked
 */
void	eat(t_philo *self)
{
	if (self->id == self->app->conf.n - 1)
	{
		take_fork(self->app, self->id, self->fork_l);
		take_fork(self->app, self->id, self->fork_r);
	}
	else
	{
		take_fork(self->app, self->id, self->fork_r);
		take_fork(self->app, self->id, self->fork_l);
	}
	gettimeofday(&self->last_meal, NULL);
	active_sleep(self->app->life, self->app->conf.tts);
	drop_fork(self->fork_l);
	drop_fork(self->fork_r);
}
