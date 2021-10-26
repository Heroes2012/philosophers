/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:16:18 by swang             #+#    #+#             */
/*   Updated: 2021/10/26 18:59:55 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_data
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_must_eat;
	pthread_mutex_t *fork;
	pthread_mutex_t *print;
}	t_data;

typedef struct s_philo
{
	t_data *data;
	pthread_mutex_t r_fork;
	pthread_mutex_t l_fork;

}	t_philo;

int	main(int argc, char *argv[]);
