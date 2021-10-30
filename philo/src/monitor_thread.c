/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:28:38 by swang             #+#    #+#             */
/*   Updated: 2021/10/30 21:30:25 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor_thread(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	// 쓰레드가 죽으몀ㄴ data->death->check 변경하기
	while (*(philo->data->death_check) == 0)
	{
		if (philo->my_death == 0 && get_time() - philo->last_eat > (unsigned long)philo->data->time_to_die)
		{
			*philo->data->death_check = 1;
			philo->
			printf("%d 죽음\n", philo->name);
			break;
			//무조건 굶엇을때만 드렁오는 곳
		}
	}
	return (0);
	// 모두 밥을 다 먹었는지 체크(?)
}
