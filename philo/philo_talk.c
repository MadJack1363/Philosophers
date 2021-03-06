/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_talk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:36:56 by majacque          #+#    #+#             */
/*   Updated: 2022/02/18 14:23:08 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	philo_talk(t_philo *philo, char *str)
{
	long	time_stamp;

	pthread_mutex_lock(philo->tlk_stick);
	pthread_mutex_lock(&philo->access_philo);
	time_stamp = get_time_stamp() - philo->time_stamp_start;
	if (philo->stop == false)
		printf("%8ld %3d %s\n", time_stamp, philo->id, str);
	pthread_mutex_unlock(&philo->access_philo);
	pthread_mutex_unlock(philo->tlk_stick);
}
