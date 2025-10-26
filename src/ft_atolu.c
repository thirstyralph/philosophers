/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:11:30 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/10 19:31:31 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long unsigned int	ft_atolu(char *str)
{
	int				i;
	int				j;
	long unsigned	r;
	long unsigned	mult;

	i = 0;
	mult = 1;
	r = 0;
	if (str[0] == '+')
		i++;
	while (str[i] == '0')
		i++;
	j = i - 1;
	while (str[i + 1])
		i++;
	if ((i - j) > 20)
		return ((unsigned long)(-1));
	while (i > j)
	{
		if (str[i] < '0' || str[i] > '9')
			return ((unsigned long)(-1));
		r = r + ((str[i--] - '0') * mult);
		mult *= 10;
	}
	return (r);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%lu\n", ft_atolu(argv[1]));
	}
	else
		printf("NO\n");
	return (0);
}
*/
