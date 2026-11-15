/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazorin <mazorin@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 12:28:50 by mazorin           #+#    #+#             */
/*   Updated: 2026/11/15 13:03:25 by mazorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n)
{
	size_t			digits;
	unsigned int	nb;

	digits = 0;
	if (n == 0)
		digits = 1;
	if (n < 0)
	{
		digits = 1;
		nb = -(unsigned int)n;
	}
	else
		nb = n;
	while (nb)
	{
		digits++;
		nb = nb / 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	digits;
	long	nb;

	nb = n;
	digits = count_digits(n);
	str = malloc(digits + 1);
	if (!str)
		return (NULL);
	str[digits] = '\0';
	if (nb < 0)
		nb = -nb;
	while (digits--)
	{
		str[digits] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
