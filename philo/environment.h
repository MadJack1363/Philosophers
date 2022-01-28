/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:12:04 by majacque          #+#    #+#             */
/*   Updated: 2022/01/28 11:45:36 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "fork_stick.h"
# include "inputs.h"
# include "philos.h"

typedef struct s_environment	t_environment;

struct s_environment
{
	t_inputs	inputs;
	t_mutex		tlk_stick;
	t_mutex		*forks;
	t_philo		*data_philos;
	pthread_t	*philos;
};

void	launch_simulation(t_philo *data_philos, int nb_philo);

#endif
