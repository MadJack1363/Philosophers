/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:34:44 by majacque          #+#    #+#             */
/*   Updated: 2022/01/24 11:36:21 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

size_t	ft_intlen(int nb);

char	*ft_itoa(int n);

void	*ft_calloc(size_t count, size_t size);

void	ft_bzero(void *s, size_t n);

bool	ft_isdigit(int c);
bool	ft_iswspace(int c);

#endif
