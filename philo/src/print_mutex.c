/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:05:36 by swang             #+#    #+#             */
/*   Updated: 2021/11/01 14:27:16 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_mutex(int flag, t_philo *philo)
{
	pthread_mutex_lock(philo->data->print);
	if (flag == SLEEP && *philo->data->death_check == 0)
		printf("%lums %d is sleeping\n", get_time() - philo->data->start_time, philo->name);
	else if (flag == EAT && *philo->data->death_check == 0)
		printf("%lums %d is eating\n", get_time() - philo->data->start_time, philo->name);
	else if (flag == DIE && *philo->data->death_check == 1 && philo->my_death == 1)
		printf("%lums %d died\n", get_time() - philo->data->start_time, philo->name);
	else if (flag == FORK && *philo->data->death_check == 0)
		printf("%lums %d has taken a fork\n", get_time() - philo->data->start_time, philo->name);
	else if (flag == THINK && *philo->data->death_check == 0)
		printf("%lums %d is thinking\n", get_time() - philo->data->start_time, philo->name);
	usleep(10);//d약간의 딜레이
	pthread_mutex_unlock(philo->data->print);
}