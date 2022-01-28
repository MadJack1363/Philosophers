/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:12:04 by majacque          #+#    #+#             */
/*   Updated: 2022/01/28 14:13:12 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# include "fork_stick.h"
# include "inputs.h"

typedef enum e_state		t_state;

enum	e_state
{
	S_WAIT,
	S_EAT,
	S_SLEEP,
	S_THINK,
	S_DEAD
};

typedef struct s_philo		t_philo;

struct s_philo
{
	int		id;
	t_mutex	*tlk_stick;
	t_mutex	*r_fork;
	t_mutex	*l_fork;
	t_mutex	access_philo;
	t_state	state;
	bool	stop;
	long	last_eat;
	int		tt_eat;
	int		tt_sleep;
	int		tt_die;
	int		nb_time_must_eat;
};

typedef struct s_environment	t_environment;

struct s_environment
{
	t_inputs	inputs;
	t_mutex		tlk_stick;
	t_mutex		*forks;
	t_philo		*data_philos;
	pthread_t	*philos;
};

int		philos_init(t_environment *env);

void	philos_join(pthread_t *philos, int index);
void	philos_stop(t_mutex *tlk_stick, t_philo *data_philos, int index);
void	data_philos_init(t_environment *env);
void	data_philos_clean(t_philo *data_philos, int index);

void	*routine(void	*arg);
void	launch_simulation(t_philo *data_philos, int nb_philo);

#endif
