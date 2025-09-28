/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:22:59 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/28 12:45:07 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

double	integer_part(char *str)
{
	double	mult;
	double	r;
	int		i;

	i = 0;
	r = 0.0;
	mult = 1.0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] && str[i] != '.')
		i++;
	i--;
	while (str[i] && str[i] != '-' && str[i] != '+')
	{
		r += (str[i] - '0') * mult;
		mult *= 10;
		i--;
	}
	return (r);
}

double	fractional_part(char *str)
{
	double	mult;
	double	r;
	int		i;

	i = 0;
	r = 0;
	mult = 1.0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		mult /= 10;
		r += (str[i] - '0') * mult;
		i++;
	}
	return (r);
}

double	sign(char *str, double n)
{
	if (str[0] == '-')
		return (n * -1);
	else
		return (n);
}

double	ft_atod(char *str)
{
	double	r;

	r = integer_part(str) + fractional_part(str);
	return (sign(str, r));
}
