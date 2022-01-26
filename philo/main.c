/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:42:33 by majacque          #+#    #+#             */
/*   Updated: 2022/01/26 16:35:20 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	__error_usage(void)
{
	printf("usage: ./philosophers nb_of_philosophers time_to_die time_to_eat");
	printf(" time_to_sleep [nb_of_time_each_philo_must_eat]\n");
	return (1);
}

// SECURE initialisations
// ./philosophers nb_of_philo time_to_die time_to_eat time_to_sleep [nb_of_time_each_philo_must_eat]
int	main(int argc, char **argv)
{
	t_inputs	inputs;
	pthread_t	*philos; // tableau de philos
	pthread_mutex_t	*forks; // tableau de fourchettes
	pthread_mutex_t	tlk_stick;

	/*Récupération des inputs*/
	if (argc != 5 && argc != 6)
		return (__error_usage());
	if (get_inputs(&inputs, argc, argv))
		return (1);

	/*Initialisation des mutex*/
	if (pthread_mutex_init(&tlk_stick, NULL))
		return (1);
	if (forks_init(&forks, inputs.nb_philo))
	{
		pthread_mutex_destroy(&tlk_stick);
		return (1);
	}

	/*Initialisation des threads*/
	if (philos_init(&philos, inputs.nb_philo))
	{
		clean_mutex(forks, tlk_stick, inputs.nb_philo);
		return (1);
	}

	return (0);
}
