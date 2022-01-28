/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:48:00 by majacque          #+#    #+#             */
/*   Updated: 2022/01/28 14:12:44 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

/* static bool	__is_wait(t_philo *data)
{
	t_state	state;

	pthread_mutex_lock(&data->access_philo);
	state = data->state;
	pthread_mutex_unlock(&data->access_philo);
	if (state == S_WAIT)
		return (true);
	return (false);
} */

void	*routine(void	*arg)
{
	t_philo	*data;
	bool	stop;
	t_state	state;
	int		id;

	data = (t_philo *)arg;

	pthread_mutex_lock(&data->access_philo);
	state = data->state;
	id = data->id;
	pthread_mutex_unlock(&data->access_philo);

	while (state == S_WAIT)
	{
		pthread_mutex_lock(&data->access_philo);
		stop = data->stop;
		pthread_mutex_unlock(&data->access_philo);
		if (stop)
			return (0);
		pthread_mutex_lock(&data->access_philo);
		state = data->state;
		pthread_mutex_unlock(&data->access_philo);
		usleep(500);
	}
	pthread_mutex_lock(data->tlk_stick);
	printf("I am thread number %d\n", id);
	pthread_mutex_unlock(data->tlk_stick);
	return (0);
}
