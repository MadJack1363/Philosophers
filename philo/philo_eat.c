/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:45:44 by majacque          #+#    #+#             */
/*   Updated: 2022/01/31 20:41:36 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static int	__take_rfork(t_philo *philo, t_routine *data)
{
	if (is_stop(philo))
		return (1);
	if (is_starving(data))
		return (philo_die(philo));
	pthread_mutex_lock(&philo->access_philo);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_unlock(&philo->access_philo);
	if (is_starving(data))
	{
		pthread_mutex_unlock(philo->r_fork);
		return (philo_die(philo));
	}
	usleep(200);
	if (is_stop(philo))
	{
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	philo_talk(philo, "has taken a fork");
	return (0);
}

static int	__take_lfork(t_philo *philo, t_routine *data)
{
	if (is_stop(philo))
		return (1);
	if (is_starving(data))
		return (philo_die(philo));
	pthread_mutex_lock(&philo->access_philo);
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_unlock(&philo->access_philo);
	if (is_starving(data))
	{
		pthread_mutex_unlock(philo->l_fork);
		return (philo_die(philo));
	}
	usleep(200);
	if (is_stop(philo))
	{
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	philo_talk(philo, "has taken a fork");
	return (0);
}

int	philo_eat(t_philo *philo, t_routine *data)
{
	int	ret;

	if (is_alone(philo))
	{
		pthread_mutex_lock(&philo->access_philo);
		philo->state = S_WAIT;
		pthread_mutex_unlock(&philo->access_philo);
		return (0);
	}
	if (__take_rfork(philo, data))
		return (1);
	usleep(200);
	if (__take_lfork(philo, data))
	{
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	data->last_eat = get_time_stamp() - data->time_stamp_start;
	philo_talk(philo, "is eating");
	ret = 0;
	if (philo_wait(philo, data, data->tt_eat))
		ret = 1;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (ret);
}