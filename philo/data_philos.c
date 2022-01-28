/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:21:01 by majacque          #+#    #+#             */
/*   Updated: 2022/01/28 13:59:14 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

void	data_philos_init(t_environment *env)
{
	int	i;
	t_philo	*data;

	i = 0;
	while (i < env->inputs.nb_philo)
	{
		data = &env->data_philos[i];
		data->id = i + 1;
		data->tlk_stick = &env->tlk_stick;
		data->l_fork = &env->forks[i];
		if (i < env->inputs.nb_philo)
			data->r_fork = &env->forks[i + 1];
		else
			data->r_fork = &env->forks[0];
		pthread_mutex_init(&data->access_philo, NULL);
		data->state = S_WAIT;
		data->stop = false;
		data->last_eat = 0;
		data->tt_eat = env->inputs.tt_eat;
		data->tt_sleep = env->inputs.tt_sleep;
		data->tt_die = env->inputs.tt_die;
		data->nb_time_must_eat = env->inputs.nb_time_must_eat;
		i++;
	}
}

void	data_philos_clean(t_philo *data_philos, int index)
{
	int	i;
	t_philo	*data;

	i = 0;
	while (i < index)
	{
		data = &data_philos[i];
		pthread_mutex_destroy(&data->access_philo);
		i++;
	}
	free(data_philos);
}
