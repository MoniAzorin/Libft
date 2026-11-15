/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazorin <mazorin@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 18:02:24 by mazorin           #+#    #+#             */
/*   Updated: 2026/11/15 14:25:12 by mazorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && (*s1 || *s2))
	{
		if ((unsigned char)*s1 > (unsigned char)*s2)
			return (1);
		else if ((unsigned char)*s1 < (unsigned char)*s2)
			return (-1);
		s1++;
		s2++;
	}
	return (0);
}
