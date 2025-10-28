/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:50:34 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/28 20:34:25 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	active_sleep(uint32_t time, t_app *app)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while ((interval(start) < time) && get_life(app))
	{
		if (usleep(500) != 0)
			return (-1);
	}
	return (0);
}
