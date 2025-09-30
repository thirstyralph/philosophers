/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:10:33 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/30 16:59:46 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_fork	*spawn_forks(uint32_t n)
{
	uint32_t		i;
	t_fork			*r;

	r = malloc(sizeof(t_fork) * n);
	if (!r)
		return (NULL);
	i = 0;
	while (i < n)
	{
		r[i].ready = 1;
		if (pthread_mutex_init(&r[i].fork, NULL) != 0)
		{
			free(r);
			return (NULL);
		}
		i++;
	}
	return (r);
}
