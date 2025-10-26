/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:22:14 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/26 21:11:25 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	kill_philo(int id, t_app *app)
{
	pthread_mutex_lock(&app->life_lock);
	app->life = 0;
	pthread_mutex_unlock(&app->life_lock);
	safe_print(id, 4, app);
}
