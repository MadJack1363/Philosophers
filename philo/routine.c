/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:48:00 by majacque          #+#    #+#             */
/*   Updated: 2022/01/31 20:47:51 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static void	__get_data(t_philo *philo, t_routine *data)
{
	pthread_mutex_lock(&philo->access_philo);
	data->id = philo->id;
	data->tt_eat = philo->tt_eat;
	data->tt_sleep = philo->tt_sleep;
	data->tt_die = philo->tt_die;
	data->nb_time_must_eat = philo->nb_time_must_eat;
	data->time_stamp_start = philo->time_stamp_start;
	data->tt_think = 0;
	data->last_eat = 0;
	pthread_mutex_unlock(&philo->access_philo);
}

/* static void __print_data(t_mutex *tlk_stick, t_routine *data)
{
	pthread_mutex_lock(tlk_stick);
	printf("I am thread number %d\n", data->id);
	printf("tt_eat = %d, ", data->tt_eat);
	printf("tt_sleep = %d, ", data->tt_sleep);
	printf("tt_think = %d, ", data->tt_think);
	printf("tt_die = %d, ", data->tt_die);
	printf("nb_time_must_eat = %d, ", data->nb_time_must_eat);
	printf("last_eat = %ld\n", data->last_eat);
	pthread_mutex_unlock(tlk_stick);
} */

static int	__wait(t_philo *philo)
{
	bool	stop;

	while (__is_wait(philo))
	{
		pthread_mutex_lock(&philo->access_philo);
		stop = philo->stop;
		pthread_mutex_unlock(&philo->access_philo);
		if (stop)
			return (1);
		usleep(500);
	}
	return (0);
}

void	*routine(void	*arg) // TODO routine()
{
	t_philo		*philo;
	t_routine	data;

	philo = (t_philo *)arg;
	__get_data(philo, &data);
	if (__wait(philo))
		return (NULL);
	while (!is_stop(philo))
	{
		if (is_state(philo, S_THINK))
			if (philo_think(philo, &data) && !is_state(philo, S_DEAD))
				return (NULL);
		else if (is_state(philo, S_EAT))
			if (philo_eat(philo, &data) && !is_state(philo, S_DEAD))
				return (NULL); // TODO philo_eat()
		else if (is_state(philo, S_SLEEP))
			if (philo_sleep(philo, &data) && !is_state(philo, S_DEAD))
				return (NULL); // TODO philo_sleep()
		if (is_starving(&data))
			philo_die(philo);
		usleep(500);
	}
	return (NULL);
}
