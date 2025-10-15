/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:25 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/15 22:31:09 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*jose_antonio(int argc, char *argv[]) //name... init? or smth, idkb
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	t_conf			*conf;
	t_app			*app;

	conf = malloc(sizeof(t_conf));
	app = malloc(sizeof(t_app));
	*conf = parse(argc, argv);
	forks = spawn_forks(conf->n);
	if (forks == NULL)
		return (NULL);
	*app = unify(conf, forks);
	philos = spawn_threads(app);
	if (!philos)
	{
		destroy_and_free(philos, NULL);
		free(forks);
		return (NULL);
	}
	return (philos);
}

int	main(int argc, char *argv[])
{
	uint32_t		i;
	uint32_t		n;
	t_philo			*philos;
	pthread_t		monitor;

	philos = jose_antonio(argc, argv);
	monitor = spawn_monitor(philos);
	if (!monitor)
		return (1);
	i = 0;
	n = philos[0].app->conf->n;
	while (i < n)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
	free(philos->app->conf);
	destroy_and_free(philos, NULL);
	free(philos->app);
	free(philos);
	return (0);
}
