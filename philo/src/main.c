/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:28:22 by swang             #+#    #+#             */
/*   Updated: 2021/10/31 16:39:30 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philo;

	if (check_arg(argc, argv) == -1)
	{
		printf("Argument error. check your argument\n");
		printf("Usage : ./philo [number_of_philosophers] [time_to_die]");
		printf(" [time_to_eat] [time_to_sleep] [optional : ");
		printf("number_of_times_each_philosopher_must_eat]\n");
		return (-1);
	}
	if (malloc_struct(argv, &data, &philo) == -1)
	{
		printf("Failed to malloc struct.\n");
		return (-1);
	}
	init_data_struct(argc, argv, &data);
	init_philo_struct(&data, philo);
	philosopher(&data, philo);
	return (0);
}

/*
철학자는 쓰레드를 만들어서 쓰는데
함수 + 변수를 넣어주는데
변수자리에 구조체를 넣고
구조체{ 왼쪽포크 오른쪽포크,,,, 등등}......
*/
