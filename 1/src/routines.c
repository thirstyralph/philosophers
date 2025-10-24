/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:20:58 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/24 19:05:38 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//philospher 
//thinks
//takes forks
//eats
//sleeps
//dies
void	*philo_routine(void *param)
{
	t_philo	*self;

	self = (t_philo *)(param);
	while (get_life(self->app))
	{
		safe_print(self->id, 3, self->app);
		safe_print(self->id, 0, self->app);
		pthread_mutex_lock(self->fork_r);
		safe_print(self->id, 0, self->app);
		pthread_mutex_lock(self->fork_l);
		safe_print(self->id, 1, self->app);
		pthread_mutex_lock(&self->meals_lock);
		gettimeofday(&self->last_meal, NULL);
		pthread_mutex_unlock(&self->meals_lock);
		active_sleep(self->conf->tte, self->app);
		pthread_mutex_unlock(self->fork_r);
		pthread_mutex_unlock(self->fork_l);
		self->meals++;
		safe_print(self->id, 2, self->app);
		active_sleep(self->conf->tts, self->app);
	}
	return (NULL);
}

void	*monitor_routine(void *param)
{
	t_philo			*philos;
	t_conf			*conf;
	t_app			*app;
	struct timeval	time;
	uint32_t		i;

	philos = (t_philo *)(param);
	conf = philos[0].conf;
	app = philos[0].app;
	while (get_life(app))
	{
		i = 0;
		while (i < conf->n)
		{
			pthread_mutex_lock(&philos[i].meals_lock);
			time = philos[i].last_meal;
			pthread_mutex_unlock(&philos[i].meals_lock);
			if (interval(time) >= conf->ttd)
			{
				pthread_mutex_lock(&app->life_lock);
				app->life = 0;
				pthread_mutex_unlock(&app->life_lock);
				safe_print(i, 4, app);
			}
			i++;
		}
	}
	return (NULL);
}
