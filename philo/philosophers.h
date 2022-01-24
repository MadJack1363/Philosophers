/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:01:00 by majacque          #+#    #+#             */
/*   Updated: 2022/01/24 14:42:54 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# include <sys/time.h>
# include <pthread.h>

# include "libft.h"

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
