/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_life.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:30:30 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/19 16:45:49 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_life(t_app *app)
{
	int	result;

	pthread_mutex_lock(&app->life_lock);
	result = app->life;
	pthread_mutex_unlock(&app->life_lock);
	return (result);
}
