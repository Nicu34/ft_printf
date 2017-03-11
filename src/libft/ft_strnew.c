/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 18:42:43 by nmuresan          #+#    #+#             */
/*   Updated: 2016/02/16 15:54:27 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;

	string = (char*)malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	string = ft_memset(string, '\0', size + 1);
	return (string);
}
