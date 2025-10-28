/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:20:58 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/28 22:31:24 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*lonely_routine(void *param)
{
	t_philo	*self;

	self = (t_philo *)(param);
	safe_print(0, 3, self->app);
	safe_print(0, 0, self->app);
	while (get_life(self->app))
	{
		usleep(1000);
	}
	return (NULL);
}

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
		pthread_mutex_lock(self->fork_r);
		safe_print(self->id, 0, self->app);
		pthread_mutex_lock(self->fork_l);
		safe_print(self->id, 0, self->app);
		safe_print(self->id, 1, self->app);
		pthread_mutex_lock(&self->meals_lock);
		gettimeofday(&self->last_meal, NULL);
		self->meals++;
		pthread_mutex_unlock(&self->meals_lock);
		active_sleep(self->conf->tte, self->app);
		safe_print(self->id, 3, self->app);
		pthread_mutex_unlock(self->fork_r);
		pthread_mutex_unlock(self->fork_l);
		safe_print(self->id, 2, self->app);
		active_sleep(self->conf->tts, self->app);
	}
	return (NULL);
}

void	*monitor_routine(void *param)
{
	t_philo			*philos;
	t_app			*app;
	uint32_t		full_philos;
	struct timeval	time;
	uint32_t		i;

	philos = (t_philo *)(param);
	app = philos[0].app;
	full_philos = 0;
	while (get_life(app))
	{
		full_philos = 0;
		i = 0;
		while (i < app->conf->n)
		{
			get_time_full(&philos[i], &time, &full_philos);
			if (full_philos == app->conf->n && app->conf->limit != 0)
				kill_philo(i, 0, app);
			if (interval(time) > app->conf->ttd)
				kill_philo(i, 1, app);
			i++;
		}
	}
	return (NULL);
}
