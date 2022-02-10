/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:24:11 by majacque          #+#    #+#             */
/*   Updated: 2022/02/10 11:26:50 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

int	philo_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->access_philo);
	philo->state = S_DEAD;
	philo->time_stamp_die = get_time_stamp() - philo->time_stamp_start;
	pthread_mutex_unlock(&philo->access_philo);
	return (1);
}
