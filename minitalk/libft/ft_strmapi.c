/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2021/10/11 16:04:04 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		acc;
	char				*ns;

	if (!(s))
		return (NULL);
	acc = ft_strlen(s);
	ns = (char *)malloc(sizeof(char) * (acc + 1));
	if (!(ns))
		return (NULL);
	ns[acc] = '\0';
	acc = 0;
	while (s[acc])
	{
		ns[acc] = (*f)(acc, s[acc]);
		acc++;
	}
	return (ns);
}
