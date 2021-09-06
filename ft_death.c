/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 01:52:08 by ssylvana          #+#    #+#             */
/*   Updated: 2021/07/28 01:52:11 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_life_of_philo(void)
{
	int					j;
	uint64_t			time;

	j = 0;
	while (j < g_all.num_philo)
	{
		time = gettime();
		if (g_all.dead == 0 && check_death(j))
		{
			g_all.dead = 1;
			return (1);
		}
		j++;
	}
	return (0);
}

int	check_death(int num)
{
	uint64_t	time;

	time = gettime() - g_all.phil[num].last_eat;
	if (time > (uint64_t)g_all.time_die)
	{
		pthread_mutex_lock(&g_all.print);
		printf("[%llu] %d is died\n", gettime() - g_all.start_time, num + 1);
		g_all.dead = 1;
		return (1);
	}
	return (0);
}

uint64_t	ft_atoi(const char *str)
{
	int				i;
	uint64_t		sum;

	i = 0;
	sum = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		sum = sum * 10 + (str[i] - 48);
		i++;
	}
	return (sum);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
