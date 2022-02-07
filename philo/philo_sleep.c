/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:19:34 by majacque          #+#    #+#             */
/*   Updated: 2022/02/01 16:20:10 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

int	philo_sleep(t_philo *philo, t_routine *data)
{
	philo_talk(philo, "is sleeping");
	if (philo_wait(philo, data, data->tt_sleep))
		return (1);
	return (philo_set_state(philo, S_THINK, 0));
}
