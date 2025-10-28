/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:44:44 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/28 22:27:37 by ranavarr         ###   ########.fr       */
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

void	*print_usage(void)
{
	printf("invalid input\n");
	printf("usage: Program and 4 or 5 arguments\n");
	printf("./philo [number of philosophers] [time to die] [time to sleep]");
	printf("[(OPTIONAL) number of times each philosopher must eat]\n");
	printf("\nAll values must be POSITIVE and in the unsigned range!\n");
	printf("Number of philosphers is limited to 200\n");
	return (NULL);
}

//returns
//	1 if given string has anything other than numbers
//	0 if it only contains numbers
int	has_alpha(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

/*
 * checks:
 *		length of the given arguments
 *		contents of the arguments
 *	returns:
 *		1 if all arguments are below 12 characters long and only contain numbers
 *		0 if the condition is not met

int	validate_len(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 20)
			return (0);
		i++;
	}
	return (1);
}
 */

int	validate_conf(int argc, t_conf r)
{
	if (r.n == (uint32_t)(-1) || r.ttd == (uint32_t)(-1)
			|| r.tte == (uint32_t)(-1) || r.tts == (uint32_t)(-1) || r.n > 200)
		return (0);
	if (argc == 6)
	{
		if (r.limit == (uint32_t)(-1))
			return (0);
	}
	return (1);
}

t_conf	*parse(int argc, char *argv[])
{
	t_conf	*r;

	if (has_alpha(argc, argv))
		return (print_usage());
	r = malloc(sizeof(t_conf));
	if (!r)
		return (NULL);
	if ((argc == 5 || argc == 6))
	{
		r->n = ft_atolu(argv[1]);
		r->ttd = ft_atolu(argv[2]);
		r->tte = ft_atolu(argv[3]);
		r->tts = ft_atolu(argv[4]);
		if (argc == 6)
			r->limit = ft_atolu(argv[5]);
		else
			r->limit = 0;
	}
	else if ((!validate_conf(argc, *r)) || !(argc == 5 || argc == 6))
	{
		free(r);
		r = print_usage();
	}
	return (r);
}
