/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:10:33 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/28 14:06:22 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_mutex_t	*spawn_forks(uint32_t n)
{
	uint32_t		i;
	pthread_mutex_t	*r;

	r = malloc(sizeof(pthread_mutex_t) * n + 1);
	if (!r)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		if (pthread_mutex_init(&r[i], NULL) != 0)
		{
			free(r);
			return (NULL);
		}
		i++;
	}
	return (r);
}
