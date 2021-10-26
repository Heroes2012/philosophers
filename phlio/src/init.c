/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:20:55 by swang             #+#    #+#             */
/*   Updated: 2021/10/26 18:59:56 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_struct(int argc, int argv)


void	init_philo(t_philo *philo, int argc, char **argv)
{
	init_data(&(philo->data),int argc, char **argv);

}

void	init_data(t_data *data, int argc, char **argv)
{
	int fork_count;

	count = 0;
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_must_eat = ft_atoi(argv[5]);
	else
		data->num_of_must_eat = -42; // 0이면 다먹은거랑 아예 인자를 안준거랑 헷갈림
	data->fork = (pthread_mutex_t *)malloc(sizeof((pthread_mutex_t *) * ft_atoi(argv[1])); // 포크뮤택스도 필로소퍼 개수만큼..
	while (count < num_of_philo)//철학자 머릿수만큼 포크뮤택스를 만들어야함
	{
		pthread_mutex_init(&(data->fork[count]), 0);
		count++;
	}
}
