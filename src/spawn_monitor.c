/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:16:53 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/30 16:58:09 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	hunger(t_app app, struct timeval last_meal, int *life, int id)
{
	if (interval(last_meal) >= app.conf.ttd)
	{
		printf("%d has died\n", id);
		*life = 0;
	}
}

pthread_t	spawn_monitor(t_philo *philos)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, monitor_routine, philos);
	return (monitor);
}
