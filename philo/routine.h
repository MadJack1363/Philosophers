/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:28:37 by majacque          #+#    #+#             */
/*   Updated: 2022/01/28 16:29:22 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "environment.h"

typedef struct s_routine	t_routine;

struct s_routine
{
	int		id;
	int		tt_eat;
	int		tt_sleep;
	int		tt_die;
	int		nb_time_must_eat;
	long	last_eat;
};

#endif
