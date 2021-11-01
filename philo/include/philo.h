/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:16:18 by swang             #+#    #+#             */
/*   Updated: 2021/11/01 15:24:44 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define SLEEP 101
# define EAT 102
# define THINK 103
# define DIE 104
# define FORK 105
# define DROP 106


# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				*death_check;
	unsigned long	start_time;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	int				eat_count;
	int				my_death;
	int				name;
	unsigned long	last_eat;
	pthread_t		thread;
	pthread_t		monitor;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	eat;

}	t_philo;

/* main */
int				main(int argc, char *argv[]);
void			free_data(t_data *data, t_philo *philo);

/* init */
void			init_philo_struct(t_data *data, t_philo *philo);
void			init_data_struct(int argc, char *argv[], t_data *data);
int				check_arg(int argc, char *argv[]);
int				malloc_struct(char *argv[], t_data *data, t_philo **philo);

/* philosopher */
void			philosopher(t_data *data, t_philo *philo);

/* thread */
void			*philo_thread(void *param);
void			*monitor_thread(void *param);

/* utils */
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			ft_free(t_data *data, t_philo *philo);
void			ft_usleep(unsigned long time);
unsigned long	get_time(void);

/* print_mutex*/
void	print_mutex(int flag, t_philo *philo, char c);

#endif
