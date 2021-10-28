/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:03:02 by swang             #+#    #+#             */
/*   Updated: 2021/10/28 16:32:22 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philosopher(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_creat(&(philo[i].thread), NULL, &(philo_thread), (void *)philo[i]));
		pthread_creat(&(philo[i].monitor), NULL, &(monitor_thread), (void *)philo[i]);
		usleep(100); // 생성 후 시간줘서 쓰레드 꼬임 방지
		i++;
	}
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_join(&(philo[i].thread), 0);
		pthread_join(&(philo[i].monitor), 0);
		pthread_mutex_destroy(&(data->fork[i]));
		pthread_mutex_destroy(&(philo[i]->eat));
		i++;
	}
	free_struct(data, filo);
}
