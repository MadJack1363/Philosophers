/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:24:11 by majacque          #+#    #+#             */
/*   Updated: 2022/01/31 20:24:55 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

int	philo_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->access_philo);
	philo->state = S_DEAD;
	pthread_mutex_unlock(&philo->access_philo);
	philo_talk(philo, "died");
	return (1);
}
