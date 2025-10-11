/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <ranavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:27:27 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/11 20:46:25 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*self;
	int		stage;

	stage = 0;
	self = (t_philo *) arg;
	if (self->app->conf->limit == 0)
	{
		while (get_life(&(self->app->life)))
		{
			stage = life_cycle(self, stage);
		}
	}
	else
	{
		while ((self->meals < self->app->conf->limit) // no deberian parar cuando ya han comido, o eso dice Pablo, tyo que se
			&& get_life(&(self->app->life)))
		{
			stage = life_cycle(self, stage);
		}
		printf("toy lleno\n"); //Aqui en vez de esto, que modifique una flag de "full" y en la rutina del monitor que se lea
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	uint32_t		i;
	t_philo			*philos;
	t_app			*app;

	philos = (t_philo *)arg;
	app = philos[0].app;
	while (get_life(&(app->life)))
	{
		i = 0;
		while ((i < (*app).conf->n))
		{
			if (hunger(*app, philos[i].last_meal) && get_life(&(app->life) && ))
			{
				safe_print(i, 4, app);
				printf("Voy a intentar lockear life\n");
				pthread_mutex_lock(&(app->life.lock));
				app->life.state = 0;
				pthread_mutex_unlock(&(app->life.lock));
			}
			i++;
		}
	}
	printf("Fin del monitor\n");
	return (NULL);
}
