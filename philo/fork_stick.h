/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_stick.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:13:18 by majacque          #+#    #+#             */
/*   Updated: 2022/01/28 10:52:44 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_STICK_H
# define FORK_STICK_H

# include <pthread.h>

typedef pthread_mutex_t	t_mutex;

int	forks_init(t_mutex **forks, int nb_philo);
int	clean_forks_stick(t_mutex *forks, t_mutex tlk_stick, int index);
int	clean_forks(t_mutex *forks, int index);

#endif
