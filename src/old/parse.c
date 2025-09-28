/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:47 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/17 18:18:52 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
	parameters to take:
	 - number of philosophers
	 - time to die
	 - time to eat
	 - time to sleep
	 - number of times each philosopher must eat [this one is optional]
*/

void	print_usage(void)
{
	printf("usage:\n");
	printf("./philo [number of philosophers] [time to die] [time to sleep]");
	printf(" (optional) [number of times each philosopher must eat]\n");
}

t_conf	parse(int argc, char *argv[])
{
	t_conf	r;

	if (argc == 5 || argc == 6)
	{
		r.n = ft_atoi(argv[1]);
		r.ttd = ft_atoi(argv[2]);
		r.tte = ft_atoi(argv[3]);
		r.tts = ft_atoi(argv[4]);
		if (argc == 6)
			r.limit = ft_atoi(argv[5]);
	}
	else
	{
		print_usage();
		exit(1);
	}
	return (r);
}
