/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:16:27 by majacque          #+#    #+#             */
/*   Updated: 2022/01/28 10:51:27 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

# include <stddef.h>
// RLIMIT_NPROC
# include <sys/resource.h>

typedef struct s_inputs	t_inputs;

struct s_inputs
{
	int	nb_philo;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	nb_time_must_eat;
};

int		get_inputs(t_inputs *inputs, int argc, char **argv);
void	print_inputs(t_inputs *inputs);

#endif
