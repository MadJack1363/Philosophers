/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_set_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:09:55 by majacque          #+#    #+#             */
/*   Updated: 2022/02/01 16:11:46 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

int	philo_set_state(t_philo *philo, t_state new_state, int ret)
{
	pthread_mutex_lock(&philo->access_philo);
	philo->state = new_state;
	pthread_mutex_unlock(&philo->access_philo);
	return (ret);
}
