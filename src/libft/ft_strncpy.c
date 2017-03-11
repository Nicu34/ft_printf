/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 17:21:18 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:40:51 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (i < ft_strlen(src))
			dst[i] = src[i];
		else
			dst[i] = 0;
		i++;
	}
	return (dst);
}
