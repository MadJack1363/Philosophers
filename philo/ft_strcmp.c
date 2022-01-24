/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:35:56 by majacque          #+#    #+#             */
/*   Updated: 2022/01/24 11:35:59 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		nb;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	nb = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			nb = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (nb);
		}
		i++;
	}
	return (nb);
}
