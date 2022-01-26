/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:13:18 by majacque          #+#    #+#             */
/*   Updated: 2022/01/26 16:30:59 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H

# include <pthread.h>

int	forks_init(pthread_mutex_t **forks, int nb_philo);
int	clean_mutex(pthread_mutex_t *forks, pthread_mutex_t tlk_stick, int index);
int	clean_forks(pthread_mutex_t *forks, int index);

#endif
