/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:42:33 by majacque          #+#    #+#             */
/*   Updated: 2022/01/24 12:11:51 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	__error_usage(void)
{
	printf("usage: ./philosophers nb_of_philosophers time_to_die time_to_eat");
	printf(" time_to_sleep [nb_of_time_each_philo_must_eat]\n");
	return (1);
}

// struct timeval *tv
// ./philosophers nb_of_philo time_to_die time_to_eat time_to_sleep [nb_of_time_each_philo_must_eat]
int	main(int argc, char **argv)
{
	t_inputs	inputs;

	if (argc != 5 && argc != 6)
		return (__error_usage());
	if (get_inputs(&inputs, argc, argv))
		return (1);
	return (0);
}
