/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 01:52:49 by ssylvana          #+#    #+#             */
/*   Updated: 2021/07/28 01:52:52 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_phil
{
	int					is_eat;
	int					num;
	uint64_t			last_eat;
	pthread_t			thread;
	pthread_mutex_t		mutex;
}	t_phil;

typedef struct s_start_params
{
	t_phil				*phil;
	pthread_mutex_t		lock;
	pthread_mutex_t		*fork;
	pthread_mutex_t		print;
	int					num_philo;
	uint64_t			time_eat;
	uint64_t			time_die;
	uint64_t			time_sleep;
	int					dead;
	uint64_t			start_time;
}	t_start_params;

uint64_t			gettime(void);
uint64_t			ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
void				print_cur_state(char *str, int num);
int					init_struct(int argc, char **argv, t_start_params *g_ever);
int					check_death(int num);
void				sft_write(char *str, int num);
void				get_forks(int num, int prev);
int					check_life_of_philo(void);
void				*ft_philo(void *i);
void				ft_pthread_create(void);
t_start_params	g_all;

#endif
