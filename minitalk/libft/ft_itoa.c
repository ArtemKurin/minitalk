/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2021/10/11 16:04:04 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getCount(int n)
{
	int	count;
	int	i;

	i = n;
	count = 0;
	if (n < 0)
		count++;
	while (i)
	{
		i = i / 10;
		count++;
	}
	if (n == 0)
		count = 1;
	return (count);
}

static void	itoaHelper(char *res, int n, int count)
{
	int	acc;

	acc = 0;
	while (n)
	{
		res[count - acc] = n % 10 + '0';
		n = n / 10;
		acc++;
	}
}

static void	minVal(char *res, int n, int count)
{
	res[0] = '-';
	n = (n / 10) * (-1);
	res[count] = '8';
	count--;
	itoaHelper(res, n, count);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*res;

	count = getCount(n);
	res = (char *)malloc(sizeof(char) * (count + 1));
	if (!(res))
		return (NULL);
	res[count] = '\0';
	if (n < 0 && n != -2147483648)
	{
		res[0] = '-';
		n = -n;
	}
	if (n == 0)
		res[0] = '0';
	count--;
	if (n == -2147483648)
		minVal(res, n, count);
	else
		itoaHelper(res, n, count);
	return (res);
}
