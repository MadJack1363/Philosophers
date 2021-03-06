/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:48:00 by majacque          #+#    #+#             */
/*   Updated: 2022/02/18 15:19:10 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static void	__get_data(t_philo *philo, t_routine *data)
{
	pthread_mutex_lock(&philo->access_philo);
	data->id = philo->id;
	data->tt_eat = philo->tt_eat;
	data->tt_sleep = philo->tt_sleep;
	data->tt_die = philo->tt_die;
	data->time_stamp_start = philo->time_stamp_start;
	data->tt_think = philo->tt_think;
	data->right_hand = philo->right_hand;
	pthread_mutex_unlock(&philo->access_philo);
}

static int	__wait(t_philo *philo)
{
	bool	stop;

	while (is_state(philo, S_WAIT))
	{
		pthread_mutex_lock(&philo->access_philo);
		stop = philo->stop;
		pthread_mutex_unlock(&philo->access_philo);
		if (stop)
			return (1);
		usleep(500);
	}
	return (0);
}

static int	__action(t_philo *philo, t_routine *data)
{
	if (is_state(philo, S_THINK))
	{
		if (philo_think(philo, data) && !is_state(philo, S_DEAD))
			return (1);
	}
	else if (is_state(philo, S_EAT))
	{
		if (philo_eat(philo, data) && !is_state(philo, S_DEAD))
			return (1);
	}
	else if (is_state(philo, S_SLEEP))
	{
		if (philo_sleep(philo, data) && !is_state(philo, S_DEAD))
			return (1);
	}
	if (!is_state(philo, S_DEAD) && is_starving(philo))
		return (philo_die(philo));
	return (0);
}

void	*routine(void	*arg)
{
	t_philo		*philo;
	t_routine	data;

	philo = (t_philo *)arg;
	__get_data(philo, &data);
	if (__wait(philo))
		return (NULL);
	while (!is_stop(philo))
	{
		if (__action(philo, &data))
			break ;
		usleep(500);
	}
	return (NULL);
}
