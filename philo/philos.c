/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:25:05 by majacque          #+#    #+#             */
/*   Updated: 2022/01/28 14:05:59 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

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
	data_philos_init(env);
	i = 0;
	while (i < env->inputs.nb_philo)
	{
		if (pthread_create(&env->philos[i], NULL, routine, &env->data_philos[i])) // TODO routine()
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

void	philos_stop(t_mutex *tlk_stick, t_philo *data_philos, int index)
{
	int	i;
	t_philo	*data;

	pthread_mutex_lock(tlk_stick);
	i = 0;
	while (i < index)
	{
		data = &data_philos[i];
		pthread_mutex_lock(&data->access_philo);
		data->stop = true;
		pthread_mutex_unlock(&data->access_philo);
		i++;
	}
	pthread_mutex_unlock(tlk_stick);
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
