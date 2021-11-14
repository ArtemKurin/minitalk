/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2021/10/11 16:04:04 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*sCopy;

	sCopy = s;
	while (*sCopy != '\0')
		sCopy++;
	while (sCopy != s)
	{
		if (*sCopy == (unsigned char)c)
			return ((char *)sCopy);
		sCopy--;
	}
	if (*sCopy == (unsigned char)c)
		return ((char *)sCopy);
	return (NULL);
}
