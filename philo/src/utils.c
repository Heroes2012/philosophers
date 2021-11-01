/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:28:32 by swang             #+#    #+#             */
/*   Updated: 2021/11/01 20:01:45 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_free(t_data *data, t_philo *philo)
{
	//1. 동적할당한 애들 지워야함
	if (philo == NULL)
		free(philo);
	if (data->fork == NULL)
		free(data->fork);
	if (data->death_check == NULL)
		free(data->death_check);
	if (data->print == NULL)
		free(data->death_check);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 0;
	num = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		sign++;
		i++;
	}
	while (ft_isdigit(str[i]))
		num = (10 * num) + (str[i++] - '0');
	if (num > 2147483647)
		return (-1);
	return (num);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

unsigned long	get_time(void)
{
	struct	timeval tv;
	unsigned long	time;

	gettimeofday(&tv, 0);
	time = tv.tv_sec * 1000; //
	time += tv.tv_usec / 1000; //
	return (time);
}

void	ft_usleep(unsigned long time)
{
	unsigned long	old_time;

	old_time = get_time();

	while (get_time() < time + old_time)
	{
		usleep(500);
	}
}

/*
지금시간 - 아까시간 < 필로가 기다려야하는 시간(슬립/식사시간)
지금시간 < 200 + 아까시간
흐른시간 < 자는시간
흐른시간 < 먹는시간
*/

// if (philo->my_death == 0 && get_time() - philo->last_eat > (unsigned long)philo->data->time_to_die)

/*

1초 = 1000ms == 1,000,000us

ms를 기준으로 단위를 환산하면 tv_sec * 1000, tv_usec / 1000
*/
