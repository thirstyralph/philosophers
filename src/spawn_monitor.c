/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:16:53 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/15 21:27:06 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	hunger(t_app *app, t_last_meal *last_meal)
{
	int			r;	
	t_last_meal	last_copy;

	r = 0;
	pthread_mutex_lock(&last_meal->lock);
	last_copy = *last_meal;
	pthread_mutex_unlock(&last_meal->lock);
	if (interval(last_copy.time) >= app->conf->ttd)
	{
		r = 1;
	}
	return (r);
}

pthread_t	spawn_monitor(t_philo *philos)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, monitor_routine, philos);
	return (monitor);
}
