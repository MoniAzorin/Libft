/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazorin <mazorin@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:23:15 by mazorin           #+#    #+#             */
/*   Updated: 2026/11/15 14:15:02 by mazorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = 0;
	while (dst[dstlen] && dstlen < size)
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
