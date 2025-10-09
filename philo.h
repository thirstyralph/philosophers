/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:25:03 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/09 10:38:39 by ranavarr         ###   ########.fr       */
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

typedef struct s_life_state
{
	int				state;
	pthread_mutex_t	lock;
}	t_life_state;

typedef struct s_last_meal
{
	struct timeval	time;
	pthread_mutex_t	lock;
}	t_last_meal;

typedef struct s_conf
{
	long unsigned int	n;		//number of philosophers
	long unsigned int	ttd;	//time to die
	long unsigned int	tte;	//time to eat
	long unsigned int	tts;	// time to sleep
	long unsigned int	limit;	// max number of times  to eat
}	t_conf;

typedef struct s_app
{
	t_life_state	life;
	t_conf			*conf;
	pthread_mutex_t	*forks;
	struct timeval	start;
	pthread_mutex_t	print;
}	t_app;

typedef struct s_philo
{
	t_app			*app;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_t		thread;
	t_last_meal		last_meal;
	uint32_t		meals;
	uint32_t		id;
}	t_philo;

//parse.c
void					print_usage(void);
t_conf					parse(int argc, char *argv[]);
//ft_strlen.c
int						ft_strlen(const char *s);
//safe_print.c
extern long unsigned	interval(struct timeval start);
extern void				print_state(int philo, int action, struct timeval strt);
void					safe_print(int philosopher, int action, t_app *app);
//ft_atoi.c
int						ft_atoi(const char *nptr);
//routines.c
void					*philo_routine(void *arg);
void					*monitor_routine(void *arg);
//spawn_threads.c
t_philo					*spawn_threads(t_app *app);
//spawn_forks.c
pthread_mutex_t			*spawn_forks(uint32_t n);
//forks.c
pthread_mutex_t			*inipthread_mutex_ts(uint32_t n);
//utils.c
t_app					unify(t_conf *conf, pthread_mutex_t *forks);
void					destroy_and_free(t_philo *philos);
int						get_life(t_life_state *life);

//main.c
long unsigned			interval(struct timeval start);
//monitor.c
int						hunger(t_app app, t_last_meal last_meal);
pthread_t				spawn_monitor(t_philo *philos);
//active_sleep.c
int						active_sleep(t_life_state *life,
							long unsigned int time);
//life_cycle.c
int						life_cycle(t_philo *self, int stage);
//actions.c
void					eat(t_philo *self);
void					philo_sleep(t_philo *self);

#endif
