/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:50:34 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/08 16:33:54 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	active_sleep(t_life_state *life, long unsigned int time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while ((interval(start) < time) && get_life(life))
	{
		if (usleep(100) != 0)
			return (-1);
	}
	return (0);
}
