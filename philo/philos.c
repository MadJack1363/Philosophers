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
	if (pthread_mutex_init(&data_philos->access_philo, NULL))
		return (1);
	data_philos->state = S_WAIT;
	data_philos->stop = false;
	data_philos->last_eat = 0;
	if (pthread_create(&env->philos[index], NULL, routine, data_philos)) // TODO routine()
		return (1);
	return (0);
}

int	philos_init(t_environment *env)
{
	int	i;

	// TODO déplacer data_philo_create() ici
	env->philos = ft_calloc(env->inputs.nb_philo, sizeof(pthread_t));
	if (env->philos == NULL)
		return (1);
	i = 0;
	while (i < env->inputs.nb_philo)
	{
		if (philo_born(env, env->data_philos, i))
		{
			philos_stop(&env->tlk_stick, &env->data_philos[i], i - 1);
			// XXX usleep() pour laisser le temps au philos de quitter ?
			data_philos_clean(env->data_philos, i - 1);
			free(env->philos);
			return (1);
		}
		i++;
	}
	return (0);
}

int	philos_stop(t_mutex *tlk_stick, t_philo *data_philos, int index)
{
	int	i;

	pthread_mutex_lock(tlk_stick); // SECURE mutex_lock() ?
	i = 0;
	while (i < index)
	{
		pthread_mutex_lock(&data_philos[i].access_philo);
		data_philos[i].stop = true;
		pthread_mutex_unlock(&data_philos[i].access_philo);
		i++;
	}
	pthread_mutex_unlock(tlk_stick);
	return (0);
}
