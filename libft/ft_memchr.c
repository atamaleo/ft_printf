/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:50:35 by viniferr          #+#    #+#             */
/*   Updated: 2023/10/19 19:18:41 by viniferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub = (char *)s;
	while (i < n)
	{
		if (sub[i] == (char)c)
			return ((char *)sub + i);
		i++;
	}
	return (0);
}
