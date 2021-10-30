/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:31:36 by swang             #+#    #+#             */
/*   Updated: 2021/10/30 21:21:13 by swang            ###   ########.fr       */
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
	printf("%d is grap_the_fork\n", philo->name);
	return (0);
}

void	drop_the_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	printf("%d drop the fork\n", philo->name);
}

int	eat(t_philo *philo)
{
	if (grap_the_fork(philo) == -1)
		return (1); // 뮤택스 락 에러처리 1로 리턴하도록 변경
	pthread_mutex_lock(&(philo->eat));
	printf("%d is eating\n", philo->name);
	philo->last_eat = get_time();
	philo->eat_count++; //time_to_eat : 먹는시간동안 철학자는 두개의 포크를 소지하고 있어야 한다.
	pthread_mutex_unlock(&(philo->eat));
	pthread_mutex_lock(&(philo->data->print));
	if (philo->eat_count == philo->data->num_of_must_eat)
	{
		drop_the_fork(philo);
		printf("%d 다먹음\n", philo->name);
		pthread_mutex_unlock(&(philo->data->print));
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->print));
	drop_the_fork(philo);
	return (0);
}

void	*philo_thread(void *param)
{
	t_philo *philo;//여기는 어차피 필로소퍼 각자 들어오는 구역.
	unsigned long	tmp_time;

	philo = (t_philo *)param;
	if (philo->name % 2 == 0) //이름이 짝수인사람은 기다리는데 안기다려지는거 같음...
		usleep(philo->data->time_to_eat);//얼마나 기다리지? -> 먹는 시간만큼
	while (*philo->data->death_check == 0)
	{
		if (eat(philo) == 1)
			break;
		//eat함수가 진행 된 다음 death_check가 1인지 체크 후 종료해주는 부분 들어가야함
		printf("%d is sleeping\n", philo->name);
		tmp_time = get_time();
		while (*philo->data->death_check == 0 && (get_time() - tmp_time < (unsigned long)philo->data->time_to_sleep))
			usleep(500);
		//sleep 이후에도 죽은애가 있는지 체크해야함
		printf("%d is thinking\n", philo->name);
	}
	//시간끌어오는 함수 확인하기....
	return (0);
}




//시간되면 죽는거 or 다먹고 죽는거 ... 어떤거 먼저 하지?




/*
본인이 must eat	까지 다먹었어도 안먹은 애들이 있을 수 있음
먼저 다먹은애는 자는거랑 생각하는거 멈추기
time_to_eat > time_to_sleep 이면 처음에 홀수애들이 두번 먹음


//최소먹는 수가 주어지니까 많이먹어도 상관없다.
*/
