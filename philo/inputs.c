/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:01:49 by majacque          #+#    #+#             */
/*   Updated: 2022/01/21 21:44:23 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
// RLIMIT_NPROC
#include <sys/resource.h>

int	get_inputs(t_inputs *inputs, int argc, char **argv)
{
	inputs->nb_philo = ft_atoi(argv[1]);
	inputs->tt_die = ft_atoi(argv[2]);
	inputs->tt_eat = ft_atoi(argv[3]);
	inputs->tt_sleep = ft_atoi(argv[4]);
	if (inputs->nb_philo < 1 || inputs->tt_die < 1 || inputs->tt_eat < 1
		|| inputs->tt_sleep < 1)
	{
		if (inputs->nb_philo > RLIMIT_NPROC)
			printf("Too much philosophers!!\n");
		return (1);
	}
	if (argc == 6)
	{
		inputs->nb_time_must_eat = ft_atoi(argv[5]);
		if (inputs->nb_time_must_eat < 1)
			return (1);
	}
	else
		inputs->nb_time_must_eat = -1;
	return (0);
}

void	print_inputs(t_inputs *inputs)
{
	printf("nb_philo = [%d]\n", inputs->nb_philo);
	printf("time_to_die = [%d]\n", inputs->tt_die);
	printf("time_to_eat = [%d]\n", inputs->tt_eat);
	printf("time_to_sleep = [%d]\n", inputs->tt_sleep);
	printf("nb_time_each... = [%d]\n", inputs->nb_time_must_eat);
}
