/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:25:29 by majacque          #+#    #+#             */
/*   Updated: 2022/01/24 11:26:20 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int nb)
{
	size_t			len;
	unsigned int	u_nb;

	if (nb < 0)
		u_nb = -nb;
	else
		u_nb = nb;
	len = 0;
	if (nb <= 0)
		len++;
	while (u_nb > 0)
	{
		u_nb /= 10;
		len++;
	}
	return (len);
}
