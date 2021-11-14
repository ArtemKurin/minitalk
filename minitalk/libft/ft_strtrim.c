/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2021/10/11 16:04:04 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mycmp(char const s1, char const *set)
{
	while (*set != '\0' && *set != s1 && s1 != '\0')
		set++;
	return (*set - s1);
}

static int	ft_getCount(char const *s1, char const *set)
{
	size_t		i;
	size_t		acc;
	size_t		count;

	i = 0;
	acc = ft_strlen(s1);
	while (ft_mycmp(s1[i], set) == 0)
		i++;
	if (s1[i] == '\0')
		return (0);
	count = acc - i;
	while (ft_mycmp(s1[acc - 1], set) == 0)
	{
		acc--;
		count--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	size_t		count;
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	if (!(s1))
		return ((char *)s1);
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	while (ft_mycmp(s1[i], set) == 0)
		i++;
	count = ft_getCount(s1, set);
	res = (char *)malloc(sizeof(char) * (count + 1));
	if (!(res))
		return (NULL);
	while (n < count)
	{
		res[n] = s1[n + i];
		n++;
	}
	res[count] = '\0';
	return (res);
}
