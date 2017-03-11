/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_desc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:50:21 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:53:16 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flg		*set_all_flags(char *desc)
{
	t_flg	*flags;
	int		i;

	i = 1;
	flags = (t_flg*)malloc(sizeof(t_flg));
	init_flags(&flags);
	while (ft_strchr(FLAGS, desc[i]))
	{
		set_flag(flags, desc[i]);
		i++;
	}
	while (desc[i])
	{
		if (ft_strchr(FLAGS, desc[i]) && desc[i] != '0')
			set_flag(flags, desc[i]);
		i++;
	}
	return (flags);
}

int			set_fieldwidth(char *desc, va_list ap)
{
	int		lmod;
	int		i;

	lmod = 0;
	i = 1;
	while (ft_strchr(FLAGS, desc[i]))
		i++;
	if (desc[i] == '*')
	{
		lmod = va_arg(ap, int);
		++i;
	}
	if (desc[i] == '*' && ft_isdigit(desc[i + 1]))
	{
		++i;
		lmod = 0;
	}
	if (ft_isdigit(desc[i]))
		lmod = 0;
	while (ft_isdigit(desc[i]))
		lmod = lmod * 10 + (desc[i++] - '0');
	if (desc[i] == '*')
		lmod = va_arg(ap, int);
	return (lmod);
}

int			set_precision(char *desc, va_list ap)
{
	int		prec;
	int		i;
	int		pos;

	prec = 0;
	i = prec_pos(desc);
	pos = i;
	if (desc[i] == '*')
		prec = va_arg(ap, int);
	else
		while (ft_isdigit(desc[pos]))
			prec = prec * 10 + (desc[pos++] - '0');
	if (desc[i - 1] == '.' && !prec && (desc[i + 1] == '0'
				|| !ft_isdigit(desc[i + 1])))
		if (!ft_strchr(desc, '#') || (ft_strchr(desc, '#')
					&& (ft_strchr(desc, 'x') || ft_strchr(desc, 'x'))))
			prec = -1;
	if (prec < -1 || (prec == -1 && ft_strchr(desc, 'd') && ft_strchr(desc,
					'*')))
		prec = 0;
	return (prec);
}

char		*set_lenmodifier(char *desc)
{
	char	*lmod;
	int		i;

	lmod = NULL;
	i = 1;
	while (ft_strchr(FLAGS, desc[i]) && ft_strchr(PRECISION, desc[i]))
		i++;
	while (desc[i])
		if (ft_strstr((desc + i), HH) || ft_strstr((desc + i), LL))
		{
			lmod = ft_strsub(desc, i, 2);
			i += 2;
		}
		else if (ft_strchr(L_MODIFIERS, desc[i]))
		{
			lmod = ft_strsub(desc, i, 1);
			i++;
		}
		else
			i++;
	return (lmod);
}

t_content	*set_content(char *desc, va_list ap)
{
	t_content	*new;

	new = (t_content*)malloc(sizeof(t_content));
	new->flags = set_all_flags(desc);
	new->width_value = set_fieldwidth(desc, ap);
	if (new->width_value < 0)
	{
		new->width_value *= -1;
		new->flags->minus = 1;
	}
	new->precision_value = set_precision(desc, ap);
	new->lenmod = set_lenmodifier(desc);
	return (new);
}
