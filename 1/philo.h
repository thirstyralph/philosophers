/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:25:03 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/19 17:25:34 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/types.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_conf
{
	unsigned int	n;
	unsigned int	ttd;
	unsigned int	tts;
	unsigned int	tte;
	unsigned int	limit;

}	t_conf;

typedef struct s_app
{
	t_conf				*conf;
	unsigned int		life;
	struct timeval		start;
	pthread_mutex_t		print;
	pthread_mutex_t		life_lock;
}	t_app;

typedef struct s_philo
{
	pthread_t			thread;
	t_app				*app;
	t_conf				*conf;
	unsigned int		id;
	unsigned int		meals;
	struct timeval		last_meal;
	pthread_mutex_t		*fork_l;
	pthread_mutex_t		*fork_r;
	pthread_mutex_t		meals_lock;
}	t_philo;

//routines
void			*philo_routine(void *param);
//get_life.c
int				get_life(t_app *app);
//spawn_forks.c
pthread_mutex_t	*spawn_forks(unsigned int n);
int				destroy_and_free_forks(pthread_mutex_t *forks, unsigned long n);
//parse.c
t_conf			*parse(int argc, char **arg);
//ft_atolu.c
unsigned long	ft_atolu(char *str);
//philosophers.c
int				philo(int argc, char **argv);
//main.c
int				main(int argc, char **argv);

#endif
