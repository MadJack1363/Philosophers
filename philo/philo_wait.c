/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_wait.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:46:18 by majacque          #+#    #+#             */
/*   Updated: 2022/02/18 15:19:29 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

int	philo_wait(t_philo *philo, t_routine *data, int tt_wait)
{
	long	time_stamp;
	long	new_ts;

	time_stamp = get_time_stamp() - data->time_stamp_start;
	new_ts = get_time_stamp() - data->time_stamp_start;
	while (new_ts - time_stamp < tt_wait)
	{
		if (is_stop(philo))
			return (1);
		if (is_starving(philo))
			return (philo_die(philo));
		usleep(1000);
		new_ts = get_time_stamp() - data->time_stamp_start;
	}
	return (0);
}
