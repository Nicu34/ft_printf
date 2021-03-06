/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:03:04 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/02 15:08:59 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strset(char *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		b[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
