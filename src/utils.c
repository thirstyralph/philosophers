/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:24:36 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/15 22:05:30 by ranavarr         ###   ########.fr       */
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

/*
 * Function: destroy_and_free
 * takes: pointer to t_philo array
 * destroys each fork and last_meal mutex
 * destroys the print mutex
 * frees fork and philos array
 */
void	destroy_and_free(t_philo *philos, t_app *app)
{
	uint32_t	i;

	i = 0;
	while (i < app->conf->n)
	{
		if (app)
			pthread_mutex_destroy(&app->forks[i]);
		if (philos)
			pthread_mutex_destroy(&philos[i].last_meal.lock);
		i++;
	}
	pthread_mutex_destroy(&philos->app->print);
}

int	get_life(t_life_state *life)
{
	int	r;

	pthread_mutex_lock(&life->lock);
	r = life->state;
	pthread_mutex_unlock(&life->lock);
	return (r);
}

int	is_full(t_full_state *full)
{
	int	r;

	pthread_mutex_lock(&full->lock);
	r = full->state;
	pthread_mutex_unlock(&full->lock);
	return (r);
}

int	check_all_full(t_philo *philos)
{
	uint32_t	i;
	uint32_t	max;

	i = 0;
	max = philos[0].app->conf->n;
	while (i < max)
	{
		if (!is_full(&philos[i].full))
			return (0);
		i++;
	}
	return (1);
}
