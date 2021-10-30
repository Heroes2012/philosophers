/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:31:36 by swang             #+#    #+#             */
/*   Updated: 2021/10/30 16:11:21 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	grap_the_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->l_fork) != 0)
		return (-1); //뮤택스 락 에러처리?
	if (pthread_mutex_lock(philo->r_fork) != 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		return (-1);
	}
	printf("in grap_the_fork\n");
	return (0);
}

void	drop_the_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

int	eat(t_philo *philo)
{
	if (grap_the_fork(philo) == -1)
		return (-1);
	while (philo->eat_count < philo->data->num_of_must_eat) // 머스트 잇 만큼 다먹으먄
	{
		printf("[name: %d] [eat_count: %d]\n", philo->name, philo->eat_count);
		philo->eat_count++;
	}
	drop_the_fork(philo);
	return (0);
}

void	*philo_thread(void *param)
{
	t_philo *philo;//여기는 어차피 필로소퍼 각자 들어오는 구역.

	philo = (t_philo *)param;
	//홀수 쓰레드 짝수 쓰레드를 어떻게 구분하지? 필로소퍼 이름,,,(1번필로는 사실 짝수번째 철학자이다)
	if (philo->name % 2 == 0) //이름이 짝수인사람은 기다려
		usleep(philo->data->time_to_eat);//얼마나 기다리지? -> 먹는 시간만큼
	if (eat(philo) == -1)
		return (0);
	/*
	while (philo->eat_count < philo->data->num_of_must_eat) // 죽은사람이 아무도 없을 때
	{
		printf("[name: %d] [eat_count: %d]\n", philo->name, philo->eat_count);
		philo->eat_count++;
	}
	*/
	//1. 포크잡고 돌아가는지  포크잡고 먹는시간동안 잡고있어야함(다 먹고 unlock)...........

	//2.모니터쓰레드에서 death_check가 제대로 돌아가는지....

	//3. 변화한 death_check를 보고 필로소퍼가 작동을 멈추는지?...

	//시간끌어오는 함수 확인하기....
	return (0);
}
