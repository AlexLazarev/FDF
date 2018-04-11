/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:16:28 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/26 20:10:25 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoasplit(char *str, int n)
{
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	while (n)
	{
		*str = (sign * (n % 10)) + 48;
		*(++str) = (char)malloc(sizeof(char));
		n /= 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*begin;
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 1)))
		return (0);
	begin = str;
	if (n == 0)
	{
		*str = '0';
		*(++str) = (char)malloc(sizeof(char));
	}
	str = ft_itoasplit(str, n);
	if (n < 0)
	{
		*str = '-';
		*(++str) = (char)malloc(sizeof(char));
	}
	*str = 0;
	return (ft_strrvrs(begin));
}
