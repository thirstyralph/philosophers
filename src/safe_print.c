/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:03 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/01 16:55:40 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

inline long unsigned	interval(struct timeval start)
{
	long unsigned	zero;
	struct timeval	end;

	zero = start.tv_sec * 1000 + start.tv_usec;
	gettimeofday(&end, NULL);
	return (((end.tv_sec * 1000) + end.tv_usec) - zero);
}

inline void	print_state(int philosopher, int action, struct timeval start)
{
	printf("%lu %d ", interval(start), philosopher);
	if (action == 0)
		printf("has taken a fork");
	else if (action == 1)
		printf("is eating");
	else if (action == 2)
		printf("is thinking");
	else if (action == 3)
		printf("is sleeping");
	else if (action == 4)
		printf("has died");
	printf("\n");
}

void	safe_print(int philosopher, int action, t_app *app)
{
	pthread_mutex_lock(&app->print);
	print_state(philosopher, action, app->start);
	pthread_mutex_unlock(&app->print);
}
