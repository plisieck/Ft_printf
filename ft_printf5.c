/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 21:18:44 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/07 21:30:00 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*treat_largeur2(char *str, t_specs opt, char c, int *tab)
{
	while (ft_strlen(str) + tab[4] < (unsigned int)opt.largeur)
	{
		if (tab[0] && opt.largeur == -1)
			opt.precision -= 1;
		if (opt.flags & 0x08 && (opt.precision != 0 ||
			!(verif_str("dDxXiuUoO", c))))
		{
			if (opt.precision <= 0 || verif_str("cCsS", c))
				str = ft_strjoin("0", str);
			else
				str = ft_strjoin(" ", str);
			if (str[0] == '-')
				tab[0] = 1;
		}
		else
		{
			if (!(opt.flags & 0x04))
				str = ft_strjoin(" ", str);
			else
				str = ft_strjoin(str, " ");
		}
	}
	return (str);
}

char	*treat_largeur3(char *str, t_specs opt, int *tab)
{
	if (opt.flags & 0x08 && (tab[0] || tab[1] || tab[3]))
	{
		if (tab[0])
			str = ft_strjoin("-", str);
		if (tab[3])
			str[1] = 'x';
		if (tab[1])
			str[0] = ' ';
	}
	return (str);
}

char	*treat_largeur(char *str, t_specs opt, char c, int z)
{
	int *tab;

	if (ft_strlen(str) > (unsigned int)opt.largeur)
		return (str);
	tab = init_tab();
	if (opt.flags & 0x08 && opt.precision == -1 &&
			(str[0] == '-' || str[0] == ' ' ||
		str[0] == '+' || str[1] == 'x'))
	{
		tab = asign_tab(tab, opt, str);
		if (str[1] != 'x')
			str++;
	}
	if (tab[0])
		opt.largeur -= 1;
	tab[4] = z;
	str = treat_largeur2(str, opt, c, tab);
	if (tab[2] == 1)
		str[0] = '+';
	str = treat_largeur3(str, opt, tab);
	return (str);
}

char	*treat_flag_space(char *str, t_specs opt, char c)
{
	if (c != 'd' && c != 'D' && c != 'i')
		return (str);
	if (str[0] != '-' && opt.flags & 0x01)
		str = ft_strjoin(" ", str);
	return (str);
}

wchar_t	*wtreat_precision(wchar_t *wstr, t_specs opt, char c)
{
	if (opt.precision == -1 || c == 'C')
		return (wstr);
	if (c != 'c' && (unsigned int)opt.precision < ft_wstrlen(wstr))
		wstr = ft_wstrsub(wstr, 0, opt.precision);
	if (c == 'S' && (unsigned int)opt.precision < ft_wstrlen(wstr))
		wstr = ft_wstrsub(wstr, 0, opt.precision);
	return (wstr);
}
