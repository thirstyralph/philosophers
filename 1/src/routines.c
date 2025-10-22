/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:20:58 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/22 18:18:30 by ranavarr         ###   ########.fr       */
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
		safe_print(self->id, 3, self->app);	//think
		safe_print(self->id, 0, self->app);	//take forks
		pthread_mutex_lock(self->fork_r);
		safe_print(self->id, 0, self->app);	//take forks
		pthread_mutex_lock(self->fork_l);
		safe_print(self->id, 1, self->app);	//eat
		pthread_mutex_unlock(self->fork_r);
		pthread_mutex_unlock(self->fork_l);
		active_sleep(self->conf->tte, self->app);
		safe_print(self->id, 2, self->app);	//sleep
		active_sleep(self->conf->tts, self->app);
	}
	return (NULL);
}
