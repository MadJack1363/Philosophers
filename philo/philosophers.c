/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:25:05 by majacque          #+#    #+#             */
/*   Updated: 2022/01/26 16:31:59 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philos_init(pthread_t **philos, int nb_philo)
{
	int	i;

	*philos = ft_calloc(nb_philo, sizeof(pthread_t));
	if (*philos == NULL)
		return (1);
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_create(&(*philos)[i], NULL, routine, arg_routine)) // TODO routine()
		{
			// TODO voir pour dire aux philos déjà créé qu'il faut sortir
			free(*philos);
			return (1);
		}
		i++;
	}
	return (0);
}
