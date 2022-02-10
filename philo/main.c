/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:42:33 by majacque          #+#    #+#             */
/*   Updated: 2022/02/10 09:27:26 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "environment.h"

static int	__error_usage(void)
{
	printf("usage: ./philosophers nb_of_philosophers time_to_die time_to_eat");
	printf(" time_to_sleep [nb_of_time_each_philo_must_eat]\n");
	return (1);
}

static void	__clean_env(t_environment *env)
{
	clean_forks_stick(env->forks, &env->tlk_stick, env->inputs.nb_philo);
	data_philo_clean(env->data_philo, env->inputs.nb_philo);
	free(env->philos);
}

int	main(int argc, char **argv)
{
	t_environment	env;

	if (argc != 5 && argc != 6)
		return (__error_usage());
	if (get_inputs(&env.inputs, argc, argv))
		return (1);
	if (pthread_mutex_init(&env.tlk_stick, NULL))
		return (1);
	if (forks_init(&env.forks, env.inputs.nb_philo))
	{
		pthread_mutex_destroy(&env.tlk_stick);
		return (1);
	}
	if (philos_init(&env))
	{
		clean_forks_stick(env.forks, &env.tlk_stick, env.inputs.nb_philo);
		return (1);
	}
	run_simulation(&env, env.inputs.nb_philo);
	__clean_env(&env);
	return (0);
}
