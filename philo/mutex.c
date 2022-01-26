/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:11:45 by majacque          #+#    #+#             */
/*   Updated: 2022/01/26 16:31:50 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutex.h"

int	clean_forks(pthread_mutex_t *forks, int index)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (i < index)
	{
		ret += pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
	if (ret > 0)
		ret = 1;
	return (ret);
}

int	clean_mutex(pthread_mutex_t *forks, pthread_mutex_t tlk_stick, int index)
{
	int	ret;
	int	i;

	ret = 0;
	ret += pthread_mutex_destroy(&tlk_stick);
	ret += clean_forks(forks, index);
	if (ret > 0)
		ret = 1;
	return (ret);
}

int	forks_init(pthread_mutex_t **forks, int nb_philo)
{
	int	i;

	*forks = ft_calloc(nb_philo, sizeof(pthread_mutex_t));
	if (*forks == NULL)
		return (1);
	i = 0;
	while (i < nb_philo)
	{
		if (phtread_mutex_init(&(*forks)[i], NULL))
		{
			clean_forks(*forks, i - 1);
			return (1);
		}
		i++;
	}
	return (0);
}
