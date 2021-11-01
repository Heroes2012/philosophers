/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:31:36 by swang             #+#    #+#             */
/*   Updated: 2021/11/01 19:57:41 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*only_one(t_philo *philo)
{
	unsigned long	tmp_time;

	print_mutex(FORK, philo, 0);
	tmp_time = get_time();
	ft_usleep(philo->data->time_to_die);
	return (0);
}

int	grap_the_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->l_fork) != 0)
		return (-1);
	print_mutex(FORK, philo, 'l');
	if (pthread_mutex_lock(philo->r_fork) != 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		return (-1);
	}
	print_mutex(FORK, philo, 'r');
	return (0);
}

void	drop_the_fork(t_philo *philo)
{
	//print_mutex(DROP, philo, 'l');
	pthread_mutex_unlock(philo->l_fork);
//	print_mutex(DROP, philo, 'r');
	pthread_mutex_unlock(philo->r_fork);
}

int	eat(t_philo *philo)
{

	if (grap_the_fork(philo) == -1)
		return (1); // 뮤택스 락 에러처리 1로 리턴하도록 변경
	pthread_mutex_lock(&(philo->eat));
	print_mutex(EAT, philo, 0);
	philo->eat_count++; //time_to_eat : 먹는시간동안 철학자는 두개의 포크를 소지하고 있어야 한다.
	philo->last_eat = get_time();
	pthread_mutex_unlock(&(philo->eat));
	ft_usleep(philo->data->time_to_eat);
	if (philo->eat_count == philo->data->num_of_must_eat)
	{
		drop_the_fork(philo);
		return (1);
	}
	drop_the_fork(philo);
	return (0);
}

void	*philo_thread(void *param)
{
	t_philo *philo;//여기는 어차피 필로소퍼 각자 들어오는 구역.

	philo = (t_philo *)param;
	
	if (philo->data->num_of_philo == 1)
		return (only_one(philo));
	if (philo->name % 2 == 0) //이름이 짝수인사람은 기다리는데 안기다려지는거 같음...
		ft_usleep(philo->data->time_to_eat);//얼마나 기다리지? -> 먹는 시간만큼
	while (*philo->data->death_check == 0)
	{
		if (eat(philo) == 1)
			break ;
		if (*philo->data->death_check == 1)
			break ;
		print_mutex(SLEEP, philo, 0);
		ft_usleep(philo->data->time_to_sleep);
		if (*philo->data->death_check == 1)
			break ;
		print_mutex(THINK, philo, 0);
		usleep(100);
	}
	//시간끌어오는 함수 확인하기....
	return (0);
}




//시간되면 죽는거 or 다먹고 죽는거 ... 어떤거 먼저 하지?


//ft_usleep
//print()






/*
본인이 must eat	까지 다먹었어도 안먹은 애들이 있을 수 있음
먼저 다먹은애는 자는거랑 생각하는거 멈추기
time_to_eat > time_to_sleep 이면 처음에 홀수애들이 두번 먹음


//최소먹는 수가 주어지니까 많이먹어도 상관없다.
*/
