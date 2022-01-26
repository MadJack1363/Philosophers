/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:11:45 by majacque          #+#    #+#             */
/*   Updated: 2022/01/26 20:41:08 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO renommer mutex.c --> forks_stick.c
#include "mutex.h"

int	clean_forks(t_mutex *forks, int index)
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

int	clean_forks_stick(t_mutex *forks, t_mutex tlk_stick, int index)
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

int	forks_init(t_mutex **forks, int nb_philo)
{
	int	i;

	*forks = ft_calloc(nb_philo, sizeof(t_mutex));
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
