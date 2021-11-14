/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2021/10/11 16:04:04 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;
	size_t		lenStr;

	i = 0;
	if (!(s))
		return (NULL);
	lenStr = ft_strlen(s);
	if (start >= lenStr)
		return (ft_calloc(1, 1));
	if (len >= ft_strlen(s + start))
		res = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	else
		res = (char *)malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	while (i < len && i < lenStr)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
