/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:20:58 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/19 17:25:24 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//philospher 
//thinks
//takes forks
//eats
//sleeps
//dies
void	*philo_routine(void *param)
{
	t_philo	*self;

	self = (t_philo *)(param);
	while (get_life(self->app))
		printf("sigo vivo\n");
}
