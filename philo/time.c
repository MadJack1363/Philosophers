/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:16:48 by majacque          #+#    #+#             */
/*   Updated: 2022/01/31 18:17:37 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/time.h>

long	get_time_stamp(void)
{
	struct timeval	tv;
	long			time_stamp;

	gettimeofday(&tv, NULL);
	time_stamp = tv.tv_sec * 1000;
	time_stamp += tv.tv_usec / 1000;
	return (time_stamp);
}
