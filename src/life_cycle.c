/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:47:20 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/01 17:18:50 by ranavarr         ###   ########.fr       */
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
	if (self->app->life)
	{
		if (stage == 0)
		{
			eat(self);
		}
		else if (stage == 1)
		{
			safe_print(self->id, 1, self->app);
		}
		else if (stage == 2)
		{
			safe_print(self->id, 2, self->app);
		}
	}
	return ((stage + 1) % 3);
}
