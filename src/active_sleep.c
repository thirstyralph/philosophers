/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:50:34 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/01 17:48:05 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	active_sleep(int *life, uint32_t time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (interval(start) < time && *life)
	{
		if (usleep(10) != 0)
			return (-1);
	}
	return (0);
}
