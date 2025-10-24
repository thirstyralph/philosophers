/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:33:37 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/24 19:03:08 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
 * t_app innit
 * parses the given arguments
 * declares and alloc's the conf array
 * declares and alloc's the t_app struct
 * return:
 * 	On success: t_app struct
 * 	On failure: NULL;
 */
t_app	*init(int argc, char **argv)
{
	t_app	*app;
	t_conf	*conf;

	conf = parse(argc, argv);
	if (!conf)
		return (NULL);
	app = malloc(sizeof(t_app));
	if (!app)
		return (free(conf), NULL);
	if (pthread_mutex_init(&app->life_lock, NULL))
	{
		free(conf);
		free(app);
		return (NULL);
	}
	if (pthread_mutex_init(&app->print, NULL))
	{
		free(conf);
		free(app);
		return (NULL);
	}
	gettimeofday(&app->start, NULL);
	app->conf = conf;
	app->life = 1;
	return (app);
}

/*
 * int	philo
 * 1. parse, reads arguments and returns t_conf struct;
 * 2. app gets declared and app.life_lock init;
 * 3. spawn_forks, t_fork array gets alloc'd and init;
 * 4. spawn_philos, for each and in alterning order:
 * 		- t_philo array gets alloc'd
 * 		- forks get asigned
 * 		- meals_lock gets init
 * 		- last_meal gets set to conf->start
 * 5. the hapeningenging happens
 * 6. t_fork array gets destroyed and free
 * 7. print lock gets destroyed
 * 8. meals lock gets destroyed
 * 9. t_philo array gets freed
 */
int	philo(int argc, char **argv)
{
	t_app			*app;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_t		monitor;

	app = init(argc, argv);
	if (!app)
		return (1);
	forks = spawn_forks(app->conf->n);
	if (!forks)
		return (1);
	philos = spawn_threads(app, forks);
	if (pthread_create(&monitor, NULL, monitor_routine, (void *)philos))
		return (1);
	join_philos(philos);
	free(app->conf);
	free(app);
	return (0);
}
