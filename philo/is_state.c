/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:40:54 by majacque          #+#    #+#             */
/*   Updated: 2022/01/31 20:36:34 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

bool	is_stop(t_philo *philo)
{
	bool	stop;

	pthread_mutex_lock(&philo->access_philo);
	stop = philo->stop;
	pthread_mutex_unlock(&philo->access_philo);
	if (stop)
		return (true);
	return (false);
}

bool	is_state(t_philo *philo, t_state state)
{
	t_state	tmp;

	pthread_mutex_lock(&philo->access_philo);
	tmp = philo->state;
	pthread_mutex_unlock(&philo->access_philo);
	if (tmp == state)
		return (true);
	return (false);
}

bool	is_starving(t_routine *data)
{
	long	time_stamp;

	time_stamp = get_time_stamp() - data->time_stamp_start;
	if (time_stamp - data->last_eat >= data->tt_die)
		return (true);
	return (false);
}

bool	is_alone(t_philo *philo)
{
	bool	alone;

	pthread_mutex_lock(&philo->access_philo);
	if (philo->r_fork == philo->l_fork)
		alone = true;
	else
		alone = false;
	pthread_mutex_unlock(&philo->access_philo);
	if (alone)
		return (true);
	return (false);
}
