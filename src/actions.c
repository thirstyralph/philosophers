/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:24:47 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/15 22:32:57 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	take_fork(t_app *app, uint32_t id, pthread_mutex_t *fork)
{
	if (pthread_mutex_lock(fork))
	{
		safe_print(id, 0, app);
		return (0);
	}
	return (1);
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
 * take_fork only works while life == 1 so if that's not true, we 
 * unlock an unlock mutex...
 */
void	eat(t_philo *self) //estou bastante seguro de que aqui no suelto los mutexesseses cuando se me muer eun filosofo
{
	int	taken[2];

	taken[0] = 0;
	taken[1] = 0;
	if (!get_life(&self->app->life))
		return ;
	safe_print(self->id, 3, self->app);
	if (self->id % 2 == 0)
	{
		if (!take_fork(self->app, self->id, self->fork_r))	//aqui hacer una array tamaño 2 para saber donde se ha bloqueado y dodne no, o algo asi, no s
			taken[0] = 1;
		if (!take_fork(self->app, self->id, self->fork_l))
			taken[1] = 1;
	}
	else
	{
		if (take_fork(self->app, self->id, self->fork_r))
			taken[0] = 1;
		if (take_fork(self->app, self->id, self->fork_l))
			taken[1] = 1;
	}
	if (get_life(&self->app->life))
	{
		safe_print(self->id, 1, self->app);
		pthread_mutex_lock(&(self->last_meal.lock));
		gettimeofday(&(self->last_meal.time), NULL);
		pthread_mutex_unlock(&(self->last_meal.lock));
		active_sleep(&(self->app->life), self->app->conf->tte);
	}
	if (taken[0])
		drop_fork(self->fork_l);
	if (taken[1])
		drop_fork(self->fork_r);
	self->meals++;
}

/*
void	eat(t_philo *self)
{
	if (get_life(&self->app->life) == 1)
	{
		take_fork(self->app, self->id, self->fork_r);
		if (get_life(&self->app->life) == 1)
		{
			take_fork(self->app, self->id, self->fork_l);
			if (get_life(&self->app->life) == 1)
			{
				safe_print(self->id, 1, self->app);
				pthread_mutex_lock(&(self->last_meal.lock));
				gettimeofday(&(self->last_meal.time), NULL);
				pthread_mutex_unlock(&(self->last_meal.lock));
				active_sleep(&(self->app->life), self->app->conf->tte);
			}
			drop_fork(self->fork_l);
		}
		drop_fork(self->fork_r);
		self->meals++;
	}
}
*/
void	philo_sleep(t_philo *self)
{
	safe_print(self->id, 2, self->app);
	active_sleep(&self->app->life, self->app->conf->tts);
}
