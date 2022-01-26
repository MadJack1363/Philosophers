/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:01:49 by majacque          #+#    #+#             */
/*   Updated: 2022/01/26 15:23:15 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inputs.h"

static int	__error(char *str)
{
	printf("%s\n", str);
	return (1);
}

int	get_inputs(t_inputs *inputs, int argc, char **argv)
{
	inputs->nb_philo = ft_atoi(argv[1]);
	inputs->tt_die = ft_atoi(argv[2]);
	inputs->tt_eat = ft_atoi(argv[3]);
	inputs->tt_sleep = ft_atoi(argv[4]);
	if (__check_input(argv[1]) || __check_input(argv[2])
		|| __check_input(argv[3]) || __check_input(argv[4]))
		return (__error("Arguments can be only positive integers"));
	if (inputs->nb_philo > RLIMIT_NPROC)
		return (__error("Too much philosophers !!"));
	if (argc == 6)
	{
		inputs->nb_time_must_eat = ft_atoi(argv[5]);
		if (__check_input(argv[5]))
			return (__error("Arguments can be only positive integers"));
	}
	else
		inputs->nb_time_must_eat = -1;
	return (0);
}

static int	__check_input(char *str)
{
	char	*tmp;
	int		nb;

	nb = ft_atoi(str);
	tmp = ft_itoa(nb);
	if (tmp == NULL)
		return (1);
	if (*str == '+')
		str++;
	if (ft_strcmp(tmp, str))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	if (nb < 1)
		return (1);
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
