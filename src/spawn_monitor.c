/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:16:53 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/08 18:15:15 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	hunger(t_app app, t_last_meal last_meal)
{
	int	r;	

	r = 0;
	pthread_mutex_lock(&last_meal.lock);
	if (interval(last_meal.time) >= app.conf->ttd)
	{
		r = 1;
	}
	pthread_mutex_unlock(&last_meal.lock);
	return (r);
}

pthread_t	spawn_monitor(t_philo **philos)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, monitor_routine, philos);
	return (monitor);
}
