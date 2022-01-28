/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:21:01 by majacque          #+#    #+#             */
/*   Updated: 2022/01/28 10:46:19 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

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
