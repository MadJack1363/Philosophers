/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:45:44 by majacque          #+#    #+#             */
/*   Updated: 2022/02/09 03:51:15 by majacque         ###   ########.fr       */
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
	/* pthread_mutex_unlock(&philo->access_philo);
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
	philo_talk(philo, "has taken a fork"); */
	if (is_starving(data))
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(&philo->access_philo);
		return (philo_die(philo));
	}
	pthread_mutex_lock(philo->tlk_stick);
	long time_stamp = get_time_stamp() - philo->time_stamp_start;
	if (philo->stop == false)
		printf("%ld %d %s\n", time_stamp, philo->id, "has taken a fork\n");
	pthread_mutex_unlock(philo->tlk_stick);
	pthread_mutex_unlock(&philo->access_philo);
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
	/* pthread_mutex_unlock(&philo->access_philo);
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
	philo_talk(philo, "has taken a fork"); */
	if (is_starving(data))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(&philo->access_philo);
		return (philo_die(philo));
	}
	pthread_mutex_lock(philo->tlk_stick);
	long time_stamp = get_time_stamp() - philo->time_stamp_start;
	if (philo->stop == false)
		printf("%ld %d %s\n", time_stamp, philo->id, "has taken a fork\n");
	pthread_mutex_unlock(philo->tlk_stick);
	pthread_mutex_unlock(&philo->access_philo);
	return (0);
}

/* bool	__is_right_hand(t_philo *philo)
{
	bool	hand;

	pthread_mutex_lock(&philo->access_philo);
	hand = philo->right_hand;
	pthread_mutex_unlock(&philo->access_philo);
	return (hand);
} */

int	philo_eat(t_philo *philo, t_routine *data)
{
	int	ret;

	if (is_alone(philo))
		return (philo_set_state(philo, S_WAIT, 0));
	/* if (__is_right_hand(philo))
	{
		if (__take_rfork(philo, data))
			return (1);
		usleep(200);
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
		usleep(200);
		if (__take_rfork(philo, data))
		{
			pthread_mutex_unlock(philo->l_fork);
			return (1);
		}
	} */
	if (__take_lfork(philo, data))
		return (1);
	usleep(200);
	if (__take_rfork(philo, data))
	{
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	/* if (__take_rfork(philo, data))
		return (1);
	usleep(200);
	if (__take_lfork(philo, data))
	{
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	} */
	data->last_eat = get_time_stamp() - data->time_stamp_start;
	pthread_mutex_lock(&philo->access_philo);
	philo->nb_time_eat += 1;
	pthread_mutex_unlock(&philo->access_philo);
	philo_talk(philo, "is eating");
	ret = 0;
	if (philo_wait(philo, data, data->tt_eat))
		ret = 1;
	// philo_talk(philo, "finish eating");
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	if (ret)
		return (philo_set_state(philo, S_WAIT, ret));
	return (philo_set_state(philo, S_SLEEP, ret));
}
