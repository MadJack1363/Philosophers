/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:56:25 by majacque          #+#    #+#             */
/*   Updated: 2022/01/28 17:41:33 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

static void	__run_even_philos(t_philo *data_philo, int nb_philo)
{
	int		i;
	t_philo	*data;

	i = 0;
	while (i < nb_philo)
	{
		data = &data_philo[i];
		pthread_mutex_lock(&data->access_philo);
		data->state = S_THINK;
		pthread_mutex_unlock(&data->access_philo);
		i += 2;
	}
	usleep(500);
	i = 1;
	while (i < nb_philo)
	{
		data = &data_philo[i];
		pthread_mutex_lock(&data->access_philo);
		data->state = S_THINK;
		pthread_mutex_unlock(&data->access_philo);
		i += 2;
	}
}

static void	__run_odd_philos(t_philo *data_philo, int nb_philo)
{
	int		i;
	t_philo	*data;

	i = 0;
	while (i < nb_philo)
	{
		data = &data_philo[i];
		pthread_mutex_lock(&data->access_philo);
		data->state = S_THINK;
		pthread_mutex_unlock(&data->access_philo);
		i += 3;
	}
	usleep(500);
	i = 1;
	while (i < nb_philo)
	{
		data = &data_philo[i];
		pthread_mutex_lock(&data->access_philo);
		data->state = S_THINK;
		pthread_mutex_unlock(&data->access_philo);
		i += 3;
	}
	usleep(500);
	i = 2;
	while (i < nb_philo)
	{
		data = &data_philo[i];
		pthread_mutex_lock(&data->access_philo);
		data->state = S_THINK;
		pthread_mutex_unlock(&data->access_philo);
		i += 3;
	}
}

/* static bool	__is_dead(t_philo *data)
{
	t_state state;

	pthread_mutex_lock(&data->access_philo);
	state = data->state;
	pthread_mutex_unlock(&data->access_philo);
	if (state == S_DEAD)
		return (true);
	return (false);
} */

void	run_simulation(t_environment *env, int nb_philo)
{
	/* int		i;
	t_philo	*data; */

	if (nb_philo % 2 == 0)
		__run_even_philos(env->data_philo, nb_philo);
	else
		__run_odd_philos(env->data_philo, nb_philo);
	/* i = 0;
	data = &data_philo[0];
	while (!__is_dead(data))
	{
		i++;
		if (i == nb_philo)
			i = 0;
		data = &data_philo[i];
	}
	philos_stop(tlk_stick, data_philo, nb_philo); */
	philos_join(env->philos, nb_philo);
}
// odd = impaire
// even = paire
