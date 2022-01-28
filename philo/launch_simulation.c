/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:56:25 by majacque          #+#    #+#             */
/*   Updated: 2022/01/28 11:03:56 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

int	launch_simulation(t_philo *data_philos, int nb_philo)
{
	if (nb_philo % 2 == 0)
	{
		__launch_even_philos(data_philos, nb_philo); // TODO launch_even_philos()
	}
	else
	{
		__launch_odd_philos(data_philos, nb_philo); // TODO launch_odd_philos()
	}
	return (0);
}
// odd = impaire
// even = paire
