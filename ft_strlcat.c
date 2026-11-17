/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazorin <mazorin@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:23:15 by mazorin           #+#    #+#             */
/*   Updated: 2026/11/16 22:26:13 by mazorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = 0;
	while (dstlen < size && dst[dstlen])
		dstlen++;
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (size + srclen);
	dst = dst + dstlen;
	size = size - dstlen - 1;
	while (size-- && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (dstlen + srclen);
}
