/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:43:12 by majacque          #+#    #+#             */
/*   Updated: 2022/01/26 16:30:31 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>

typedef struct s_philo		t_philo;
typedef enum e_philo_state	t_philo_state;

struct s_philo
{
	pthread_mutex_t	*tlk_stick;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_philo_state	state;
	bool			stop;
	long			last_eat;
};

enum	e_philo_state
{
	S_WAIT,
	S_EAT,
	S_SLEEP,
	S_THINK,
	S_DEAD
};

int	philos_init(pthread_t **philos, int nb_philo);

#endif
