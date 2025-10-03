/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:47 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/02 18:11:33 by ranavarr         ###   ########.fr       */
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
	printf("usage: Program and 4 or 5 arguments\n");
	printf("./philo [number of philosophers] [time to die] [time to sleep]");
	printf("[(OPTIONAL) number of times each philosopher must eat]\n");
	printf("\nAll values must be POSITIVE and in the INT range!\n");
}

//returns
//	1 if given string has anything other than numbers
//	0 if it only contains numbers
int	has_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

/*
 * checks:
 *		length of the given arguments
 *		contents of the arguments
 *	returns:
 *		1 if all arguments are bellow 12 characters long and only contain numbers
 *		0 if the condition is not met
 */
int	validate_len_and_chars(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) >= 11 || has_alpha(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

t_conf	parse(int argc, char *argv[])
{
	t_conf	r;

	if ((argc == 5 || argc == 6) && validate_len_and_chars(argc, argv))
	{
		r.n = ft_atoi(argv[1]);
		r.ttd = ft_atoi(argv[2]) * 1000;
		r.tte = ft_atoi(argv[3]) * 1000;
		r.tts = ft_atoi(argv[4]) * 1000;
		if (argc == 6)
			r.limit = ft_atoi(argv[5]);
		else
			r.limit = 0;
	}
	else
	{
		print_usage();
		exit(1);
	}
	return (r);
}
