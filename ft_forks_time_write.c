/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks_time_write.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 01:52:20 by ssylvana          #+#    #+#             */
/*   Updated: 2021/07/28 01:52:24 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_cur_state(char *str, int num)
{
	pthread_mutex_lock(&g_all.print);
	printf("[%llu] %d %s\n", gettime() - g_all.start_time, num + 1, str);
	pthread_mutex_unlock(&g_all.print);
}

void	get_forks(int num, int prev)
{
	pthread_mutex_lock(&g_all.lock);
	pthread_mutex_lock(&g_all.phil[prev].mutex);
	print_cur_state("has taken a fork", (num + 1));
	pthread_mutex_lock(&g_all.phil[num].mutex);
	print_cur_state("has taken a fork", (num + 1));
	pthread_mutex_unlock(&g_all.lock);
}

uint64_t	gettime(void)
{
	struct timeval		tme;
	uint64_t			tii;

	gettimeofday(&tme, NULL);
	tii = (tme.tv_usec / 1000) + (tme.tv_sec * 1000);
	return (tii);
}
