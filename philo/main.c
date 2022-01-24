/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:42:33 by majacque          #+#    #+#             */
/*   Updated: 2022/01/24 20:32:39 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	__error_usage(void)
{
	printf("usage: ./philosophers nb_of_philosophers time_to_die time_to_eat");
	printf(" time_to_sleep [nb_of_time_each_philo_must_eat]\n");
	return (1);
}

int	philos_init(pthread_t **philos, int nb_philo)
{
	int	i;

	*philos = ft_calloc(nb_philo + 1, sizeof(pthread_t));
	if (*philos == NULL)
		return (1);
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_create(&(*philos)[i], NULL, routine, arg_routine)) // TODO routine()
		{
			free(*philos);
			return (1);
		}
		i++;
	}
	return (0);
}

// ./philosophers nb_of_philo time_to_die time_to_eat time_to_sleep [nb_of_time_each_philo_must_eat]
int	main(int argc, char **argv)
{
	t_inputs	inputs;
	pthread_t	*philos; // tableau de philos

	if (argc != 5 && argc != 6)
		return (__error_usage());
	if (get_inputs(&inputs, argc, argv))
		return (1);
	if (philos_init(philos, inputs.nb_philo))
		return (1);
	return (0);
}
