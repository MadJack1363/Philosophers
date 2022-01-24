/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:42:33 by majacque          #+#    #+#             */
/*   Updated: 2022/01/24 15:28:53 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

typedef struct s_test	t_test;

struct s_test
{
	char	*str;
	int		nb;
};

static int	__error_usage(void)
{
	printf("usage: ./philosophers nb_of_philosophers time_to_die time_to_eat");
	printf(" time_to_sleep [nb_of_time_each_philo_must_eat]\n");
	return (1);
}

static void	*test(void *param)
{
	t_test	*data = (t_test *)param;
	printf("%s %d\n", data->str, data->nb);
	return (NULL);
}

// ./philosophers nb_of_philo time_to_die time_to_eat time_to_sleep [nb_of_time_each_philo_must_eat]
int	main(int argc, char **argv)
{
	t_inputs	inputs;
	pthread_t	thread1;
	pthread_t	thread2;
	t_test		data1;
	t_test		data2;

	if (argc != 5 && argc != 6)
		return (__error_usage());
	if (get_inputs(&inputs, argc, argv))
		return (1);

	data1.str = "Je suis le thread";
	data1.nb = 1;
	data2.str = "Je suis le thread";
	data2.nb = 2;

	if (pthread_create(&thread1, NULL, &test, &data1))
	{
		puts("Error pthread_create");
		return (0);
	}
	if (pthread_join(thread1, NULL))
	{
		puts("Error pthread_join");
		return (0);
	}
	if (pthread_create(&thread2, NULL, &test, &data2))
	{
		puts("Error pthread_create");
		return (0);
	}
	if (pthread_join(thread2, NULL))
	{
		puts("Error pthread_join");
		return (0);
	}

	puts("Fin");
	return (0);
}
