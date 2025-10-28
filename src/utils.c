/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:22:14 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/28 13:29:56 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
 * void	kill_philo
 * prints the death message if and only if a philo has died of hunger
 * and turns app->life to 0, ending the execution loop.
 */
void	kill_philo(int id, int cause, t_app *app)
{
	if (cause == 1)
		safe_print(id, 4, app);
	pthread_mutex_lock(&app->life_lock);
	app->life = 0;
	pthread_mutex_unlock(&app->life_lock);
}

void	get_time_full(t_philo *philo, struct timeval *time,
		uint32_t *full_philos)
{
	pthread_mutex_lock(&philo->meals_lock);
	*time = philo->last_meal;
	if (philo->meals >= philo->app->conf->limit)
		(*full_philos)++;
	pthread_mutex_unlock(&philo->meals_lock);
}
