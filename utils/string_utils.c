/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:30:00 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 13:46:57 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sub_size;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		sub_size = ft_strlen(s) - start;
	else
		sub_size = len;
	sub = malloc(sizeof(char) * (sub_size + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, sub_size + 1);
	return (sub);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	count = ft_strlen(src);
	if (size == 0)
		return (count);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (count);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	count;
	size_t	dst_size;

	dst_size = ft_strlen(dst);
	count = ft_strlen(src) + dst_size;
	if (size <= dst_size)
		return (size + ft_strlen(src));
	i = dst_size;
	j = 0;
	while (i < size - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (count);
}
