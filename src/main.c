/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:25 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/03 14:45:54 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
 * Parse, se devuelve conf struct
 * Se inician los mutex, de print y tenedores
 * se inician los hilos, filosofos y monitor
 * Al morir un filosofo, ocurrir algun error o llegar al limite
 * Se liberan todas las arrays (filosofos y tenedores)
 * return (0);
 */
int	main(int argc, char *argv[])
{
	uint32_t		i;
	t_conf			conf;
	t_app			app;
	t_philo			*philos;
	pthread_t		monitor;
	pthread_mutex_t	*forks;

	conf = parse(argc, argv);
	forks = spawn_forks(conf.n);
	//aqui lo que deberia de hacer es declarar todos los mutex a la vez
	if (forks == NULL)
		return (1);
	app = unify(&conf, forks);
	philos = spawn_threads(&app);
	if (!philos)
	{
		free(forks);
		return (1);
	}
	monitor = spawn_monitor(&philos);
	i = 0;
	while (i < conf.n)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
	destroy_forks(&app);
	free(philos);
	return (0);
}
