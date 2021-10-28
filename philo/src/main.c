/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:28:22 by swang             #+#    #+#             */
/*   Updated: 2021/10/28 14:57:09 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check_arg(int argc, char *argv[])
{
	int	i;
	int	j;

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

static int	malloc_struct(char *argv[], t_data *data, t_philo **philo)
{
	*philo = (t_philo *)malloc(sizeof((t_philo) * ft_atoi(argv[1]));


}

int main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philo;

	if (check_arg(argc, argv) == -1)
	{
		printf("Argument error. check your argument\n");
		printf("Usage : ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional : number_of_times_each_philosopher_must_eat]\n");
		return (-1);
	}
	if (malloc_struct(argv[1], &data, &philo) == -1)
	{
		printf("Failed to malloc.\n");
		return (-1);
	}
	init_data(&data);
	init_philo(&data, philo);
	philosopher(&data, philo);
	return (0);
}

/*
철학자는 쓰레드를 만들어서 쓰는데
함수 + 변수를 넣어주는데
변수자리에 구조체를 넣고
구조체{ 왼쪽포크 오른쪽포크,,,, 등등}......
*/
