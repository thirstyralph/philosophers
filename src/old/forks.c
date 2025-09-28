/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:09 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/17 18:18:19 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_mutex_t	*init_forks(uint32_t n)
{
	uint32_t		i;
	pthread_mutex_t	*r;

	i = 0;
	r = malloc(sizeof(pthread_mutex_t) * n);
	if (!r)
		return (NULL);
	while (i < n)
	{
		if (pthread_mutex_init(&r[i], NULL) != 0)
		{
			while (i > 0)
				pthread_mutex_destroy(&r[--i]);
			free(r);
			return (NULL);
		}
		i++;
	}
	return (r);
}
