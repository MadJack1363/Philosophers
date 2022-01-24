/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:42:33 by majacque          #+#    #+#             */
/*   Updated: 2022/01/24 18:38:43 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

typedef struct s_test	t_test;

struct s_test
{
	char	*str;
	int		nb;
	pthread_mutex_t	*mutex;
};

static int	__error_usage(void)
{
	printf("usage: ./philosophers nb_of_philosophers time_to_die time_to_eat");
	printf(" time_to_sleep [nb_of_time_each_philo_must_eat]\n");
	return (0);
}

static void	*test(void *param)
{
	t_test	*data = (t_test *)param;

	pthread_mutex_lock(data->mutex);
	printf("%s %d\n", data->str, data->nb);
	pthread_mutex_unlock(data->mutex);
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
	pthread_mutex_t	baton_parole;

	if (argc != 5 && argc != 6)
		return (__error_usage());
	if (get_inputs(&inputs, argc, argv))
		return (0);

	pthread_mutex_init(&baton_parole, NULL);
	data1.str = "Je suis le thread";
	data1.nb = 1;
	data1.mutex = &baton_parole;
	data2.str = "Je suis le thread";
	data2.nb = 2;
	data2.mutex = &baton_parole;

	pthread_create(&thread1, NULL, &test, &data1);
	pthread_create(&thread2, NULL, &test, &data2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	pthread_mutex_destroy(&baton_parole);
	puts("Fin");
	return (0);
}
