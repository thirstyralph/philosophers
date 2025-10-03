/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:16:53 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/02 18:14:47 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	hunger(t_app app, struct timeval last_meal)
{
	if (interval(last_meal) >= app.conf.ttd)
	{
		printf("illo que hambre tengo\n");
		return (1);
	}
	return (0);
}

pthread_t	spawn_monitor(t_philo **philos)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, monitor_routine, philos);
	return (monitor);
}
