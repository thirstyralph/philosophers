/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:24:36 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/02 13:56:19 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_app	unify(t_conf *conf, pthread_mutex_t *forks)
{
	t_app			app;

	app.conf = *conf;
	app.forks = forks;
	app.life = 1;
	pthread_mutex_init(&app.print, NULL);
	gettimeofday(&app.start, NULL);
	return (app);
}

void	destroy_forks(t_app *app)
{
	uint32_t	i;

	i = 0;
	while (i < app->conf.n)
	{
		pthread_mutex_destroy(&app->forks[i]);
		i++;
	}
	free(app->forks);
}
