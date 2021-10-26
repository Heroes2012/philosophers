/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:28:22 by swang             #+#    #+#             */
/*   Updated: 2021/10/26 18:59:58 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		pritnf("argument error. check your argument\n");
		return (-1);
	}
	else
	{
		t_philo *philo;
		init_sturct(philo, argc, argv);
		phliosopher(philo);
		free(philo);
		return (0);
	}
}

/*
철학자는 쓰레드를 만들어서 쓰는데
함수 + 변수를 넣어주는데
변수자리에 구조체를 넣고
구조체{ 왼쪽포크 오른쪽포크,,,, 등등}......
*/
