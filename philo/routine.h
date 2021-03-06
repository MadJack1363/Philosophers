/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:28:37 by majacque          #+#    #+#             */
/*   Updated: 2022/02/18 15:16:52 by majacque         ###   ########.fr       */
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
	int		tt_think;
	int		tt_die;
	long	time_stamp_start;
	bool	right_hand;
};

bool	is_stop(t_philo *philo);
bool	is_state(t_philo *philo, t_state state);
bool	is_starving(t_philo *philo);
bool	is_dead(t_philo *philo);
bool	is_alone(t_philo *philo);

int		philo_set_state(t_philo *philo, t_state new_state, int ret);
int		philo_wait(t_philo *philo, t_routine *data, int tt_wait);
int		philo_eat(t_philo *philo, t_routine *data);
int		philo_sleep(t_philo *philo, t_routine *data);
int		philo_think(t_philo *philo, t_routine *data);
int		philo_die(t_philo *philo);

void	philo_talk(t_philo *philo, char *str);

#endif
