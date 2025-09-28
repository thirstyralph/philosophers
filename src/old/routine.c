/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:57 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/28 11:41:05 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_forks(int fork_l, int fork_r)
{
	mutex_lock(&forks[fork_l]);
	safe_print(
	mutex_lock(&forks[fork_l]);
}
/*
 *	casts argument to t_app 
 * eat
 * 		take(mutex_lock) two forks
 * 		eat(sleep for x time)
 * 		drop (mutex_unlock) the forks)
 * sleep
 * think
 */
void	*_philo_routine(void *arg)
{
	t_app		*app;
	uint32_t	meals;

	meals = 0;
	app = (t_app *)arg;
	while (meals < app->conf.limit && interval(*app->start) < app->conf.ttd)
	{
		safe_print(0, 0, *app);
		safe_print(1, 0, *app);
		safe_print(2, 0, *app);
		safe_print(3, 0, *app);
		safe_print(4, 0, *app);
	}
	return (NULL);
}
