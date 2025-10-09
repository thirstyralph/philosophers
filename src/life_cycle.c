/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:47:20 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/08 16:36:07 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

/*
 * 0. takes forks
 * 1. eats
 * 2. sleeps
 * 3. thinks
 * 4. may die
 */
int	life_cycle(t_philo *self, int stage)
{
	if (get_life(&(self->app->life)))
	{
		if (stage == 0 && &(self->app->life))
		{
			eat(self);
		}
		else if (stage == 1 && &(self->app->life))
		{
			philo_sleep(self);
		}
	}
	return ((stage + 1) % 2);
}
