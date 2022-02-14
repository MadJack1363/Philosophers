/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:56:25 by majacque          #+#    #+#             */
/*   Updated: 2022/02/14 10:00:55 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static void	__run_philos(t_philo *data_philo,
							int nb_philo, int index, int increment)
{
	t_philo	*data;
	int		i;

	i = index;
	while (i < nb_philo)
	{
		data = &data_philo[i];
		pthread_mutex_lock(&data->access_philo);
		data->state = S_EAT;
		pthread_mutex_unlock(&data->access_philo);
		i += increment;
	}
}

static void	__run_even_philos(t_environment *env, int nb_philo)
{
	__run_philos(env->data_philo, nb_philo, 0, 2);
	usleep(env->inputs.tt_eat / 2 * 1000);
	__run_philos(env->data_philo, nb_philo, 1, 2);
}

static void	__run_odd_philos(t_environment *env, int nb_philo)
{
	__run_philos(env->data_philo, nb_philo, 0, 3);
	usleep(env->inputs.tt_eat / 2 * 1000);
	__run_philos(env->data_philo, nb_philo, 1, 3);
	usleep(env->inputs.tt_eat / 2 * 1000);
	__run_philos(env->data_philo, nb_philo, 2, 3);
}

static t_philo	*__check_philo_state(t_environment *env, int nb_philo)
{
	int		i;
	int		nb_philo_full;
	t_philo	*data;

	i = 0;
	nb_philo_full = 0;
	data = &env->data_philo[0];
	while (!is_state(data, S_DEAD) && nb_philo_full != nb_philo)
	{
		pthread_mutex_lock(&data->access_philo);
		if (!data->full && data->nb_time_eat == env->inputs.nb_time_must_eat)
		{
			data->full = true;
			nb_philo_full++;
		}
		pthread_mutex_unlock(&data->access_philo);
		i++;
		if (i == nb_philo)
		{
			usleep(200);
			i = 0;
		}
		data = &env->data_philo[i];
	}
	return (data);
}

void	run_simulation(t_environment *env, int nb_philo)
{
	t_philo	*philo;

	if (nb_philo % 2 == 0)
		__run_even_philos(env, nb_philo);
	else
		__run_odd_philos(env, nb_philo);
	philo = __check_philo_state(env, nb_philo);
	if (is_state(philo, S_DEAD))
	{
		pthread_mutex_lock(&env->tlk_stick);
		printf("%ld %d died\n", philo->time_stamp_die, philo->id);
		pthread_mutex_unlock(&env->tlk_stick);
	}
	philos_stop(&env->tlk_stick, env->data_philo, nb_philo);
	philos_join(env->philos, nb_philo);
}
// odd = impaire
// even = paire
