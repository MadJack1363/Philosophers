/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:45:44 by majacque          #+#    #+#             */
/*   Updated: 2022/02/18 16:00:04 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static int	__take_rfork(t_philo *philo, t_routine *data)
{
	(void)data;
	if (is_stop(philo))
		return (1);
	if (is_starving(philo))
		return (philo_die(philo));
	pthread_mutex_lock(philo->r_fork);
	if (is_stop(philo))
	{
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	if (is_starving(philo))
	{
		pthread_mutex_unlock(philo->r_fork);
		return (philo_die(philo));
	}
	philo_talk(philo, "has taken a fork");
	return (0);
}

static int	__take_lfork(t_philo *philo, t_routine *data)
{
	(void)data;
	if (is_stop(philo))
		return (1);
	if (is_starving(philo))
		return (philo_die(philo));
	pthread_mutex_lock(philo->l_fork);
	if (is_stop(philo))
	{
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	if (is_starving(philo))
	{
		pthread_mutex_unlock(philo->l_fork);
		return (philo_die(philo));
	}
	philo_talk(philo, "has taken a fork");
	return (0);
}

static int	__take_forks(t_philo *philo, t_routine *data)
{
	if (data->right_hand)
	{
		if (__take_rfork(philo, data))
			return (1);
		if (__take_lfork(philo, data))
		{
			pthread_mutex_unlock(philo->r_fork);
			return (1);
		}
	}
	else
	{
		if (__take_lfork(philo, data))
			return (1);
		if (__take_rfork(philo, data))
		{
			pthread_mutex_unlock(philo->l_fork);
			return (1);
		}
	}
	return (0);
}

static void	__release_forks(t_philo *philo, t_routine *data)
{
	if (data->right_hand)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
}

int	philo_eat(t_philo *philo, t_routine *data)
{
	int	ret;

	if (is_alone(philo))
	{
		philo_talk(philo, "I need more fork... I'm gonna die... I'll wait...");
		return (philo_set_state(philo, S_WAIT, 0));
	}
	if (__take_forks(philo, data))
		return (1);
	philo_talk(philo, "is eating");
	pthread_mutex_lock(&philo->access_philo);
	philo->last_eat = get_time_stamp() - data->time_stamp_start;
	philo->nb_time_eat += 1;
	pthread_mutex_unlock(&philo->access_philo);
	ret = 0;
	if (philo_wait(philo, data, data->tt_eat))
		ret = 1;
	__release_forks(philo, data);
	if (ret)
		return (1);
	return (philo_set_state(philo, S_SLEEP, ret));
}
