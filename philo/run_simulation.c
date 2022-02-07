/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:56:25 by majacque          #+#    #+#             */
/*   Updated: 2022/02/01 20:11:20 by majacque         ###   ########.fr       */
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
	usleep(1000);
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

static bool	__is_dead(t_philo *data)
{
	t_state state;

	pthread_mutex_lock(&data->access_philo);
	state = data->state;
	pthread_mutex_unlock(&data->access_philo);
	if (state == S_DEAD)
		return (true);
	return (false);
}

void	run_simulation(t_environment *env, int nb_philo)
{
	int		i;
	int		nb_philo_full;
	t_philo	*data;

	if (nb_philo % 2 == 0)
		__run_even_philos(env->data_philo, nb_philo);
	else
		__run_odd_philos(env->data_philo, nb_philo);
	i = 0;
	nb_philo_full = 0;
	data = &env->data_philo[0];
	while (!__is_dead(data) && nb_philo_full != nb_philo)
	{
		pthread_mutex_lock(&data->access_philo);
		if (data->nb_time_eat == env->inputs.nb_time_must_eat)
			nb_philo_full++;
		pthread_mutex_unlock(&data->access_philo);
		i++;
		if (i == nb_philo)
		{
			usleep(200);
			i = 0;
		}
		data = &env->data_philo[i];
	}
	philos_stop(&env->tlk_stick, env->data_philo, nb_philo);
	philos_join(env->philos, nb_philo);
}
// odd = impaire
// even = paire
