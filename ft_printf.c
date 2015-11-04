/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 23:41:27 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 18:46:28 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_option_printf(va_list ap, char *c, int *i, t_specs opt)
{
	char		*str;
	wchar_t		*wstr;
	int			r;

	str = NULL;
	wstr = NULL;
	if (c[*i] == 'c' && !(opt.modif & 0x04))
		str = ft_option_c(ap);
	else if (c[*i] == 'C' || (c[*i] == 'c' && opt.modif & 0x04))
		wstr = ft_option_big_c(ap);
	else if (verif_str("bkqtQfFegdDiEGpoOuUxX", c[*i]))
		str = treat_convs(ap, opt, c, i);
	else if (c[*i] == 's' && !(opt.modif & 0x04))
		str = treat_conv_s(ap, opt, c, i);
	else if ((c[*i] == 'S' || (c[*i] == 's' && opt.modif & 0x04)))
		wstr = treat_conv_big_s(ap, opt, c, i);
	else
		str = treat_else(opt, c, i);
	if (c[*i] == 'c' && !(opt.modif & 0x04) && (r = opt2(opt, c, i, &str)) > 0)
		return (r);
	else if ((c[*i] == 'C' || ((c[*i] == 'c') && opt.modif & 0x04))
			&& (r = ft_option_big_c2(opt, c, i, &wstr)) > 0)
		return (r);
	split_if(str, &i);
	return ((r = split_if2(&wstr, i)) ? r : (int)ft_strlen(str));
}

void	ft_printf2(char *c, int *i, int *len)
{
	ft_putchar(c[*i]);
	(*len)++;
	(*i)++;
}

void	init_tab2(int tab[2])
{
	tab[0] = 0;
	tab[1] = 0;
}

int		ft_printf(char const *format, ...)
{
	int			tab[2];
	va_list		ap;
	char		*c;
	t_specs		opt;

	init_tab2(tab);
	c = ft_strdup(format);
	va_start(ap, format);
	while (c[tab[0]])
	{
		if (c[tab[0]] == '{' && verif_colour(c, tab[0]))
			c = treat_colours(c, &tab[0]);
		else if (c[tab[0]] == '%')
		{
			opt = check_options(ap, format, &tab[0]);
			if (c[tab[0]] == 'n')
				treat_n(ap, &tab[0], tab[1]);
			else
				tab[1] += ft_option_printf(ap, c, &tab[0], opt);
		}
		else
			ft_printf2(c, &tab[0], &tab[1]);
	}
	va_end(ap);
	return (tab[1]);
}
