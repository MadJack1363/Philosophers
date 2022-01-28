/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:56:25 by majacque          #+#    #+#             */
/*   Updated: 2022/01/28 11:45:30 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "environment.h"

void	__launch_even_philos(t_philo *data_philos, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_lock(&data_philos[i].access_philo);
		data_philos->state = S_THINK;
		pthread_mutex_unlock(&data_philos[i].access_philo);
		i += 2;
	}
	usleep(500);
	i = 1;
	while (i < nb_philo)
	{
		pthread_mutex_lock(&data_philos[i].access_philo);
		data_philos->state = S_THINK;
		pthread_mutex_unlock(&data_philos[i].access_philo);
		i += 2;
	}
}

void	__launch_odd_philos(t_philo *data_philos, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_lock(&data_philos[i].access_philo);
		data_philos->state = S_THINK;
		pthread_mutex_unlock(&data_philos[i].access_philo);
		i += 3;
	}
	usleep(500);
	i = 1;
	while (i < nb_philo)
	{
		pthread_mutex_lock(&data_philos[i].access_philo);
		data_philos->state = S_THINK;
		pthread_mutex_unlock(&data_philos[i].access_philo);
		i += 3;
	}
	usleep(500);
	i = 3;
	while (i < nb_philo)
	{
		pthread_mutex_lock(&data_philos[i].access_philo);
		data_philos->state = S_THINK;
		pthread_mutex_unlock(&data_philos[i].access_philo);
		i += 3;
	}
}

void	launch_simulation(t_philo *data_philos, int nb_philo)
{
	if (nb_philo % 2 == 0)
		__launch_even_philos(data_philos, nb_philo);
	else
		__launch_odd_philos(data_philos, nb_philo);
}
// odd = impaire
// even = paire
