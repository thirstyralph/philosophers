/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:25:03 by ranavarr          #+#    #+#             */
/*   Updated: 2025/10/23 19:41:05 by ranavarr         ###   ########.fr       */
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
	uint32_t	n;
	uint32_t	ttd;
	uint32_t	tts;
	uint32_t	tte;
	uint32_t	limit;

}	t_conf;

typedef struct s_app
{
	t_conf				*conf;
	uint32_t			life;
	struct timeval		start;
	pthread_mutex_t		print;
	pthread_mutex_t		life_lock;
}	t_app;

typedef struct s_philo
{
	pthread_t			thread;
	t_app				*app;
	t_conf				*conf;
	uint32_t			id;
	uint32_t			meals;
	struct timeval		last_meal;
	pthread_mutex_t		*fork_l;
	pthread_mutex_t		*fork_r;
	pthread_mutex_t		meals_lock;
}	t_philo;

//safe_print.c
void				safe_print(int philo, int action, t_app *app);
//spawn_threads
t_philo				*spawn_threads(t_app *app, pthread_mutex_t *forks);
void				join_philos(t_philo *philos);
//active_sleep.c
long unsigned		interval(struct timeval start);
int					active_sleep(uint32_t time, t_app *app);
//routines
void				*philo_routine(void *param);
void				*monitor_routine(void *param);
//get_life.c
int					get_life(t_app *app);
//spawn_forks.c
pthread_mutex_t		*spawn_forks(uint32_t n);
void				destroy_and_free_forks(pthread_mutex_t *forks, uint32_t n);
//parse.c
t_conf				*parse(int argc, char **arg);
//ft_atolu.c
unsigned long		ft_atolu(char *str);
//philosophers.c
int					philo(int argc, char **argv);
//main.c
int					main(int argc, char **argv);

#endif
