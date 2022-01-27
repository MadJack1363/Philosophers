/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:25:05 by majacque          #+#    #+#             */
/*   Updated: 2022/01/26 19:07:45 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

static int	philo_born(t_environment *env, t_philo *data_philos, int index)
{
	data_philos->id = index + 1;
	data_philos->tlk_stick = &env->tlk_stick;
	data_philos->l_fork = &env->forks;
	if (index < env->inputs.nb_philo)
		data_philos->r_fork = &env->forks[index + 1];
	else
		data_philos->r_fork = &env->forks[0];
	pthread_mutex_init(&data_philos->access_philo, NULL);
	data_philos->state = S_WAIT;
	data_philos->stop = false;
	data_philos->last_eat = 0;
	data_philos->tt_eat = env->inputs.tt_eat;
	data_philos->tt_sleep = env->inputs.tt_sleep;
	data_philos->tt_die = env->inputs.tt_die;
	data_philos->nb_time_must_eat = env->inputs.nb_time_must_eat;
	if (pthread_create(&env->philos[index], NULL, routine, data_philos)) // TODO routine()
		return (1);
	return (0);
}

int	philos_init(t_environment *env)
{
	int	i;

	env->philos = ft_calloc(env->inputs.nb_philo, sizeof(pthread_t));
	env->data_philos = ft_calloc(env->inputs.nb_philo, sizeof(t_philo));
	if (env->philos == NULL || env->data_philos == NULL)
	{
		free(env->philos);
		free(env->data_philos);
		return (1);
	}
	i = 0;
	while (i < env->inputs.nb_philo)
	{
		if (philo_born(env, env->data_philos, i))
		{
			philos_stop(&env->tlk_stick, &env->data_philos[i], i - 1);
			philos_join(env->philos, i - 1);
			data_philos_clean(env->data_philos, i - 1);
			free(env->philos);
			return (1);
		}
		i++;
	}
	return (0);
}

void	philos_join(pthread_t *philos, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
}

void	philos_stop(t_mutex *tlk_stick, t_philo *data_philos, int index)
{
	int	i;

	pthread_mutex_lock(tlk_stick);
	i = 0;
	while (i < index)
	{
		pthread_mutex_lock(&data_philos[i].access_philo);
		data_philos[i].stop = true;
		pthread_mutex_unlock(&data_philos[i].access_philo);
		i++;
	}
	pthread_mutex_unlock(tlk_stick);
}
