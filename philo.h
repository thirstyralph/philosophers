/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:25:03 by ranavarr          #+#    #+#             */
/*   Updated: 2025/09/28 11:51:20 by ranavarr         ###   ########.fr       */
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

// que pasa si limit es 0? lo acepto y no les dejo comer?
typedef struct s_conf
{
	uint32_t	n;		//number of philosophers
	uint32_t	ttd;	//time to die
	uint32_t	tte;	//time to eat
	uint32_t	tts;	// time to sleep
	uint32_t	limit;	// max number of times for the philosophers to eat
}	t_conf;

typedef struct s_app
{
	t_conf			conf;
	struct timeval	*start;
	pthread_mutex_t	*forks;	
	pthread_mutex_t	*print;
}	t_app;

typedef struct s_philo
{
	t_app			*app;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_t		thread;
	long long		last_meal;
	uint32_t		meals;
	uint32_t		id;
}	t_philo;

//safe_print.c
extern long unsigned	interval(struct timeval start);
extern void				print_state(int philo, int action, struct timeval strt);
void					safe_print(int philosopher, int action, t_app app);
//ft_atoi.c
int						ft_atoi(const char *nptr);
//routine.c
void					*_philo_routine(void *arg);
//spawn_threads.c
pthread_t				*spawn_threads(t_app app);
//spawn_forks.c
pthread_mutex_t			*spawn_forks(uint32_t n);
//forks.c
pthread_mutex_t			*init_forks(uint32_t n);
//parse.c
void					print_usage(void);
t_conf					parse(int argc, char *argv[]);
//utils.c
t_app					unify(t_conf *conf, pthread_mutex_t *forks);
//main.c
long unsigned			interval(struct timeval start);

#endif
