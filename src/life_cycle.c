/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:47:20 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/02 17:22:05 by ranavarr         ###   ########.fr       */
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
	if (self->app->life == 1)
	{
		if (stage == 0 && self->app->life == 1)
		{
			eat(self);
		}
		else if (stage == 1 && self->app->life == 1)
		{
			philo_sleep(self);
		}
	}
	return ((stage + 1) % 2);
}
