/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:24:36 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/08 18:09:12 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_app	unify(t_conf *conf, pthread_mutex_t *forks)
{
	t_app			app;

	app.conf = conf;
	app.forks = forks;
	app.life.state = 1;
	pthread_mutex_init(&app.print, NULL);
	pthread_mutex_init(&app.life.lock, NULL);
	gettimeofday(&app.start, NULL);
	return (app);
}

void	destroy_forks(t_app *app)
{
	uint32_t	i;

	i = 0;
	while (i < app->conf->n)
	{
		pthread_mutex_destroy(&app->forks[i]);
		i++;
	}
	free(app->forks);
}

int	get_life(t_life_state *life)
{
	int	r;

	pthread_mutex_lock(&life->lock);
	r = life->state;
	pthread_mutex_unlock(&life->lock);
	return (r);
}
