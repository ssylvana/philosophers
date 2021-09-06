/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 01:53:01 by ssylvana          #+#    #+#             */
/*   Updated: 2021/07/28 01:53:03 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(void *i)
{
	int	num;
	int	prev;

	num = *(int *)i;
	prev = num - 1;
	if (prev < 0)
		prev = g_all.num_philo - 1;
	g_all.phil[num].last_eat = g_all.start_time;
	while (1)
	{
		get_forks(num, prev);
		g_all.phil[num].last_eat = gettime();
		print_cur_state("is eating", (num + 1));
		usleep(1000 * g_all.time_eat);
		pthread_mutex_unlock(&g_all.phil[num].mutex);
		pthread_mutex_unlock(&g_all.phil[prev].mutex);
		print_cur_state("is sleeping", (num + 1));
		usleep(1000 * (g_all.time_sleep - (gettime()
					- g_all.phil[num].last_eat - g_all.time_eat)));
		print_cur_state("is thinking", num + 1);
	}
	return (i);
}

static void	create_cycle(int j)
{
	while (j < g_all.num_philo)
	{
		g_all.phil[j].num = j;
		g_all.phil[j].last_eat = g_all.start_time;
		pthread_create(&(g_all.phil[j].thread), NULL, ft_philo,
			(void *)&g_all.phil[j].num);
		j += 2;
	}
}

void	ft_pthread_create(void)
{
	int	j;

	j = 0;
	g_all.start_time = (gettime());
	create_cycle(j);
	usleep(1);
	j = 1;
	create_cycle(j);
}
