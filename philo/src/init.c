/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:20:55 by swang             #+#    #+#             */
/*   Updated: 2021/10/28 16:26:14 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_arg(int argc, char *argv[])
{
	int	i;
	int	j;
//atoi 에러뜨는지 argv미리 체크하기
	i = 0;
	if (argc < 5 || argc > 6)
		return (-1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	malloc_struct(char *argv[], t_data *data, t_philo **philo)
{
	*philo = (t_philo *)malloc(sizeof((t_philo) * ft_atoi(argv[1]));
	if (*philo == 0)
		return (-1);
	data->fork = (pthread_mutex_t *)malloc(sizeof((pthread_mutex_t) * ft_atoi(argv[1])));
	if (data->fork == 0)
		return (-1);
	return (0);
}

void	init_data(char *argv[], t_data *data)
{
	int count;

	count = 0;
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_must_eat = ft_atoi(argv[5]);
	else
		data->num_of_must_eat = -42; // 0이면 다먹은거랑 아예 인자를 안준거랑 헷갈림
	data->death_check = 0;
	pthread_mutex_init(&(data->print));
	while (count < num_of_philo)//철학자 머릿수만큼 포크뮤택스를 만들어야함
	{
		pthread_mutex_init(&(data->fork[count]), 0);
		count++;
	}
}

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;
	int	n_philo;

	i = 0;
	n_philo = data->num_of_philo;
	while (i < n_philo)
	{
		philo[i].eat_count = 0;
		philo[i].my_death = 0;
		philo[i].name = i + 1;
		philo[i].data = data;
		pthread_mutex_init(&(philo[i]->eat), 0);
		philo[i].l_fork = data->fork[i];
		if (i == 0)
			philo[i].r_fork = data->fork[n_philo - 1];
		else
			philo[i].r_fork = data->fork[i - 1];
		i++;
	}
}
/*

<- 철0 -> 포0 <- 철1 -> 포1 철2 -> 포2 철3 -> 포3 철4 -> 포4 철5 -> 포5

*/
