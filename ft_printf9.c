/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 14:41:19 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 17:21:04 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*treat_colours2(char *c, char *color, int *i)
{
	if (!ft_strcmp(color, "hlt"))
		c = ft_strrjoin(c, "\033[1m", *i);
	else if (!ft_strcmp(color, "rev"))
		c = ft_strrjoin(c, "\033[7m", *i);
	else if (!ft_strcmp(color, "black"))
		c = ft_strrjoin(c, "\033[30m", *i);
	else if (!ft_strcmp(color, "red"))
		c = ft_strrjoin(c, "\033[31m", *i);
	else if (!ft_strcmp(color, "green"))
		c = ft_strrjoin(c, "\033[32m", *i);
	else if (!ft_strcmp(color, "yellow"))
		c = ft_strrjoin(c, "\033[33m", *i);
	else if (!ft_strcmp(color, "blue"))
		c = ft_strrjoin(c, "\033[34m", *i);
	else if (!ft_strcmp(color, "magenta"))
		c = ft_strrjoin(c, "\033[35m", *i);
	else if (!ft_strcmp(color, "cyan"))
		c = ft_strrjoin(c, "\033[36m", *i);
	else if (!ft_strcmp(color, "white"))
		c = ft_strrjoin(c, "\033[37m", *i);
	else if (!ft_strcmp(color, "eoc"))
		c = ft_strrjoin(c, "\033[0m", *i);
	return (c);
}

char	*treat_colours(char *c, int *i)
{
	int		j;
	char	*color;

	j = 0;
	(*i)++;
	color = ft_strnew(0);
	while (c[*i] != '}')
	{
		color[j] = c[*i];
		j++;
		(*i)++;
	}
	(*i)++;
	c = treat_colours2(c, color, i);
	return (c);
}

int		verif_colour(char *c, int i)
{
	int		j;
	int		k;
	char	*str;
	char	*cpy;

	j = 0;
	k = i + 1;
	cpy = ft_strdup(c);
	str = ft_strnew(100);
	while (cpy[k] != '}')
	{
		str[j] = c[k];
		j++;
		k++;
	}
	if (!ft_strcmp(str, "black") || !ft_strcmp(str, "red") ||
			!ft_strcmp(str, "green") || !ft_strcmp(str, "yellow")
			|| !ft_strcmp(str, "blue") || !ft_strcmp(str, "magenta") ||
			!ft_strcmp(str, "cyan") || !ft_strcmp(str, "white") ||
			!ft_strcmp(str, "eoc") || !ft_strcmp(str, "hlt") ||
			!ft_strcmp(str, "rev"))
		return (1);
	return (0);
}

void	treat_n(va_list ap, int *i, int len)
{
	int	*k;

	(*i)++;
	k = va_arg(ap, int *);
	*k = len;
}

char	*treat_conv_b(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	str = ft_strdup(convertion_base(2, va_arg(ap, int), "", 0));
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}
