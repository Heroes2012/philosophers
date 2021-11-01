/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:05:36 by swang             #+#    #+#             */
/*   Updated: 2021/11/01 15:33:31 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_mutex(int flag, t_philo *philo, char c)
{
	pthread_mutex_lock(philo->data->print);
	if (flag == SLEEP && *philo->data->death_check == 0)
		printf("%lums %d is sleeping\n", get_time() - philo->data->start_time, philo->name);
	else if (flag == EAT && *philo->data->death_check == 0)
		printf("%lums %d is eating\n", get_time() - philo->data->start_time, philo->name);
	else if (flag == DIE && *philo->data->death_check == 1 && philo->my_death == 1)
		printf("%lums %d died\n", get_time() - philo->data->start_time, philo->name);
	else if (flag == FORK && *philo->data->death_check == 0)
	{
		if (c == 'l')
			printf(" philo: %d, grab l_fork : %p\n", philo->name, philo->l_fork);
		else if (c == 'r')
			printf(" philo: %d, grab r_fork : %p\n", philo->name, philo->r_fork);
		printf("%lums %d has taken a fork\n", get_time() - philo->data->start_time, philo->name);
	}
	else if (flag == THINK && *philo->data->death_check == 0)
		printf("%lums %d is thinking\n", get_time() - philo->data->start_time, philo->name);
	else if (flag == DROP && *philo->data->death_check == 0)
	{
		if (c == 'l')
			printf(" philo: %d, drop l-fork : %p\n", philo->name, philo->l_fork);
		else if (c == 'r')
			printf(" philo: %d, drop r-fork : %p\n", philo->name, philo->r_fork);
	}
	usleep(10);//d약간의 딜레이
	pthread_mutex_unlock(philo->data->print);
}