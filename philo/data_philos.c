/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:21:01 by majacque          #+#    #+#             */
/*   Updated: 2022/01/27 16:06:48 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	data_philos_create(t_philo **data_philos, int nb_philo) // FIX useless
{
	*data_philos = ft_calloc(nb_philo, sizeof(t_philo));
	if (*data_philos == NULL)
		return (1);
	return (0);
}

void	data_philos_clean(t_philo *data_philos, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		pthread_mutex_destroy(&data_philos[i]);
		i++;
	}
	free(data_philos);
}
