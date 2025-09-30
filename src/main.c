/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:25 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/30 16:35:50 by ranavarr         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	uint32_t		i;
	t_conf			conf;
	t_app			app;
	t_philo			*philos;
	pthread_t		monitor;
	t_fork			*forks;

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
/*
 #	must take:
	- number_of_philosophers
	- time_to_die
	- time_to_eat
	- time_to_sleep
	- number_of_times_each_philosopher_must_eat
	Each philosopher can use his own fork and the one to his left.
	so philosoper 0 can use fork 0 and top - 1, philo 1 can use forks 1, and 0
# How I think I will make it:
		- I start each philosopher naming it with it's position
		- I create a fork for each philosopher, and put them in an array,
			when it is time for philosophers to eat, they check if forks are
			available for them and if so they lock them with mutex and use them
int	main(int argc, char *argv[])

{
	
	return (0);
}
*/
