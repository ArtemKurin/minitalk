/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2021/10/11 16:04:04 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		n;

	if (!(s1))
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * n + 1);
	if (!(res))
		return (NULL);
	i = 0;
	res[n] = '\0';
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n])
	{
		res[i] = s2[n];
		i++;
		n++;
	}
	return (res);
}
