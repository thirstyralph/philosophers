/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:47:20 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/30 16:57:32 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

int	life_cycle(t_philo *self, int stage)
{
	if (stage == 0)
	{
		safe_print(self->id, 0, self->app);
	}
	else if (stage == 1)
	{
		safe_print(self->id, 1, self->app);
		gettimeofday(&self->last_meal, NULL);
	}
	else if (stage == 2)
	{
		safe_print(self->id, 2, self->app);
	}
	else if (stage == 3)
	{
		safe_print(self->id, 3, self->app);
	}
	return ((stage + 1) % 4);
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
		pthread_mutex_lock(self->fork_l);
		safe_print(self->id, 0, self->app);
		pthread_mutex_lock(self->fork_r);
		safe_print(self->id, 0, self->app);
	}
	else
	{
		pthread_mutex_lock(self->fork_r);
		safe_print(self->id, 0, self->app);
		pthread_mutex_lock(self->fork_l);
		safe_print(self->id, 0, self->app);
	}
	gettimeofday(&self->last_meal, NULL);
	active_sleep(&self->life, self->app->conf.tts);
	pthread_mutex_unlock(self->fork_r);
	pthread_mutex_unlock(self->fork_l);
}
