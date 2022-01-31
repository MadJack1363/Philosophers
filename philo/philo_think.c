/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:32:18 by majacque          #+#    #+#             */
/*   Updated: 2022/01/31 20:02:28 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

int	philo_think(t_philo *philo, t_routine *data)
{
	philo_talk(philo, "is thinking");
	if (philo_wait(philo, data, data->tt_think))
		return (1);
	pthread_mutex_lock(&philo->access_philo);
	philo->state = S_EAT;
	pthread_mutex_unlock(&philo->access_philo);
	return (0);
}
