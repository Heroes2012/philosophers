/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:31:36 by swang             #+#    #+#             */
/*   Updated: 2021/10/30 17:37:52 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	grap_the_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->l_fork) != 0)
	{
		printf("19\n");
		return (-1); //뮤택스 락 에러처리?
	}
	if (pthread_mutex_lock(philo->r_fork) != 0)
	{
		printf("24\n");
		pthread_mutex_unlock(philo->l_fork);
		return (-1);
	}
	printf("%d is grap_the_fork\n", philo->name);
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
	printf("%d is eating\n eat_time : %d\n", philo->name, philo->eat_count + 1);
	philo->eat_count++; //time_to_eat : 먹는시간동안 철학자는 두개의 포크를 소지하고 있어야 한다.
	if (philo->eat_count == philo->data->num_of_must_eat)
		(*philo->data->eat_check)++;
	if (*(philo->data->eat_check) == philo->data->num_of_philo)
		return (0);
	drop_the_fork(philo);
	printf("%d is sleeping\n", philo->name);
	usleep(philo->data->time_to_sleep);
	printf("%d is thinking\n", philo->name);
	return (0);
}

void	*philo_thread(void *param)
{
	t_philo *philo;//여기는 어차피 필로소퍼 각자 들어오는 구역.

	philo = (t_philo *)param;
	//홀수 쓰레드 짝수 쓰레드를 어떻게 구분하지? 필로소퍼 이름,,,(1번필로는 사실 짝수번째 철학자이다)
	if (philo->name % 2 == 0) //이름이 짝수인사람은 기다려
		usleep(philo->data->time_to_eat);//얼마나 기다리지? -> 먹는 시간만큼
	while (*(philo->data->death_check) < 1)
	{
		pthread_mutex_lock(&(philo->data->print));
		printf("%d's %d, %d\n", philo->name, philo->eat_count, philo->data->num_of_must_eat);
		pthread_mutex_unlock(&(philo->data->print));
		if (eat(philo) == -1)
			return (0);
	}
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





/*
본인이 must eat	까지 다먹었어도 안먹은 애들이 있을 수 있음
먼저 다먹은애는 자는거랑 생각하는거 멈추기
time_to_eat > time_to_sleep 이면 처음에 홀수애들이 두번 먹음


//최소먹는 수가 주어지니까 많이먹어도 상관없다.
*/