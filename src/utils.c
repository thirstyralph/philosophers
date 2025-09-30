/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:24:36 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/30 15:56:10 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_app	unify(t_conf *conf, t_fork *forks)
{
	t_app			app;

	app.conf = *conf;
	app.forks = forks;
	pthread_mutex_init(&app.print, NULL);
	gettimeofday(&app.start, NULL);
	return (app);
}

void	take_fork(void)
{
}
