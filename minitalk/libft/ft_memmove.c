/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2021/10/11 16:04:04 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*ns;
	char		*nd;

	if (!(dst) && !(src))
		return (NULL);
	if (dst < src)
	{
		ns = src;
		nd = dst;
		ft_memcpy(dst, src, len);
	}
	else if (dst >= src)
	{
		ns = src + (len - 1);
		nd = dst + (len - 1);
		while (len--)
		{
			*nd = *ns;
			nd--;
			ns--;
		}
	}
	return (dst);
}
