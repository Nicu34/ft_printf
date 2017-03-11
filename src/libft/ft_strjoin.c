/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 12:25:08 by nmuresan          #+#    #+#             */
/*   Updated: 2015/11/13 22:08:53 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new;
	char *s;

	s = ft_strdup(s1);
	new = NULL;
	new = (char*)malloc(sizeof(new) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new)
		new = ft_strcat(s, s2);
	return (new);
}
