/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:43:12 by majacque          #+#    #+#             */
/*   Updated: 2022/01/26 19:08:19 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <pthread.h>
# include <stdbool.h>

# include "environment.h"

typedef struct s_philo		t_philo;
typedef enum e_state	t_state;

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

enum	e_state
{
	S_WAIT,
	S_EAT,
	S_SLEEP,
	S_THINK,
	S_DEAD
};

int		philos_init(t_environment *env);
int		data_philos_create(t_philo **data_philos, int nb_philo);

void	philos_join(pthread_t *philos, int index);
void	philos_stop(t_mutex *tlk_stick, t_philo *data_philos, int index);
void	data_philos_clean(t_philo *data_philos, int index);

#endif
