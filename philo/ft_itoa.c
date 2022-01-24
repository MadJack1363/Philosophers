/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:24:04 by majacque          #+#    #+#             */
/*   Updated: 2022/01/24 11:26:23 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	size_t			size;
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	size = ft_intlen(n);
	str = ft_calloc((size + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		*str = '-';
	if (n == 0)
		*str = '0';
	while (nb > 0)
	{
		size--;
		str[size] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
