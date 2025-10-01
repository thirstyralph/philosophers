/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:25 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/01 17:04:02 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
void	notification(uint32_t philo, uint32_t action)
{
	//timestamp_in_ms philo has done this action or another;

}
*/
void	print_conf(t_conf conf)
{
	printf("number of philosophers = %u\n", conf.n);
	printf("time to die = %u\n", conf.ttd);
	printf("time to eat  = %u\n", conf.tte);
	printf("time to sleep  = %u\n", conf.tts);
	printf("number of times the philos must eat = %u\n", conf.limit);
}

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
	print_conf(conf);
	forks = spawn_forks(conf.n);
	if (forks == NULL)
		return (1);
	app = unify(&conf, forks);
	philos = spawn_threads(&app);
	if (!philos)
	{
		free(forks);
		return (1);
	}
	monitor = spawn_monitor(philos);
	i = 0;
	while (i < conf.n)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
	free(philos);
	free(forks);
	return (0);
}
