/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:25:03 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/03 14:45:33 by ranavarr         ###   ########.fr       */
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
	uint32_t	n;		//number of philosophers
	uint32_t	ttd;	//time to die
	uint32_t	tte;	//time to eat
	uint32_t	tts;	// time to sleep
	uint32_t	limit;	// max number of times for the philosophers to eat
}	t_conf;

typedef struct s_app
{
	int				life;
	t_conf			conf;
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
	struct timeval	last_meal;
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
void					destroy_forks(t_app *app);

//main.c
long unsigned			interval(struct timeval start);
//monitor.c
int						hunger(t_app app, struct timeval last_meal);
pthread_t				spawn_monitor(t_philo **philos);
//active_sleep.c
int						active_sleep(int *life, uint32_t time);
//life_cycle.c
int						life_cycle(t_philo *self, int stage);
//actions.c
void					eat(t_philo *self);
void					philo_sleep(t_philo *self);

#endif
