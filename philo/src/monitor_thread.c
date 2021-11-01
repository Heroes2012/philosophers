/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:28:38 by swang             #+#    #+#             */
/*   Updated: 2021/10/31 18:06:59 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor_thread(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (*philo->data->death_check == 0)
	{
		if (philo->eat_count == philo->data->num_of_must_eat)
			break ;
		if (philo->my_death == 0 && get_time() - philo->last_eat > (unsigned long)philo->data->time_to_die)
  		{
			pthread_mutex_lock(&(philo->eat));
			philo->my_death = 1;
			*philo->data->death_check += 1;
			print_mutex(DIE, philo);
			pthread_mutex_unlock(&(philo->eat));
		}
		usleep(10);
	}
	return (0);
}


/*

다먹으면 먼저 종료됨

내가 먹는동안 다른 애들이 죽었는지 체크하는 법
내가 먹고나서 다른 애들이 죽었는지 체크하는 법
내가 자는동안 다른 애들이 죽었는지 체크하는 법
내가 자고나서 다른 애들이 죽었는지 체크하는 법

//---모니터 쓰레드에서 굶는거는 항시 체크중---//
내가 대기상태(thinking)일 때 내가 굶었는지 체크하는 법
내가 대기상태일 때 다른 애들이 굶었는지 체크하는 법






timestamp_in_ms X has taken a fork

timestamp_in_ms X is eating

timestamp_in_ms X is sleeping

timestamp_in_ms X is thinking

timestamp_in_ms X died


*/
