/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:48:09 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/19 17:49:08 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned int	interval(struct timeval start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec - start.tv_sec) * 1000)
			+ ((time.tv_usec - start.tv_usec) / 1000));
}

void	active_sleep(uint32_t time, t_app *app)
{
	struct timeval	zero;

	gettimeofday(&zero, NULL);
	while ((interval(zero) < time) && get_life(app))
		usleep(1000);
}
