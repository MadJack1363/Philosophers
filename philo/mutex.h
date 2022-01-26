/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:13:18 by majacque          #+#    #+#             */
/*   Updated: 2022/01/26 19:42:55 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H

# include <pthread.h>

typedef pthread_mutex_t	t_mutex;

int	forks_init(t_mutex **forks, int nb_philo);
int	clean_forks_stick(t_mutex *forks, t_mutex tlk_stick, int index);
int	clean_forks(t_mutex *forks, int index);

#endif
