/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 01:52:34 by ssylvana          #+#    #+#             */
/*   Updated: 2021/07/28 01:52:36 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	mutex_init(t_start_params *g_all)
{
	int	j;

	j = 0;
	while (j < g_all->num_philo)
	{
		pthread_mutex_init(&g_all->phil[j].mutex, NULL);
		j++;
	}
}

static int	set_values(char **argv, t_start_params *g_all)
{
	g_all->num_philo = ft_atoi(argv[1]);
	g_all->time_die = ft_atoi(argv[2]);
	g_all->time_eat = ft_atoi(argv[3]);
	g_all->time_sleep = ft_atoi(argv[4]);
	g_all->dead = 0;
	g_all->phil = malloc(sizeof(t_phil) * g_all->num_philo);
	if (g_all->num_philo < 1 || g_all->time_die < 1
		|| g_all->time_eat < 1 || g_all->time_sleep < 1 || !g_all->phil)
	{
		write(1, "Bad arguments\n", 14);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{	
	if (argc >= 5 && argc <= 6)
	{
		if (set_values(argv, &g_all) == 1)
			return (1);
		mutex_init(&g_all);
		pthread_mutex_init(&g_all.lock, NULL);
		pthread_mutex_init(&g_all.print, NULL);
	}
	else
	{
		printf("Bad number of arguments\n");
		return (1);
	}
	ft_pthread_create();
	while (1)
	{
		if (check_life_of_philo() == 1)
			return (0);
	}
}
