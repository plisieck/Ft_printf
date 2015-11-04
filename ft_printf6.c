/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 21:29:33 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/07 23:21:31 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t *wtrt_opt(wchar_t *wstr, t_specs opt, char c, int z)
{
	wstr = wtreat_precision(wstr, opt, c);
	wstr = wtreat_largeur(wstr, opt, z);
	return (wstr);
}

char	*treat_precision1(char *str, t_specs opt, char c, int *tab)
{
	if (c != 's' && c != 'c')
	{
		if (tab[1])
			while (ft_strlen(str) + 2 < (unsigned int)opt.precision)
				str = ft_strjoin("0", str);
		else
			while (ft_strlen(str) < (unsigned int)opt.precision)
				str = ft_strjoin("0", str);
	}
	if (tab[1])
	{
		if (c == 'x' || c == 'p')
			str[1] = 'x';
		else if (c == 'X')
			str[1] = 'X';
	}
	if (tab[0])
		str = ft_strjoin("-", str);
	return (str);
}

char	*treat_precision2(char *str, t_specs opt, char c, int **tab)
{
	if (c == 's' && (unsigned int)opt.precision < ft_strlen(str))
		str = ft_strsub(str, 0, opt.precision);
	if (ft_strlen(str) > (unsigned int)opt.precision)
		return (str);
	if (str[0] == '-')
	{
		(*tab[0]) = 1;
		str++;
	}
	if (c != 'x' && c != 'X' && (unsigned int)opt.precision < ft_strlen(str))
		str = ft_strsub(str, 0, opt.precision);
	else if (c == 'x' || c == 'X' || c == 'p')
	{
		if (str[1] == 'x' || str[1] == 'X')
			str = ft_strsub(str, 2, ft_strlen(str) - 2);
		while (ft_strlen(str) < (unsigned int)opt.precision)
			str = ft_strjoin("0", str);
	}
	return (str);
}

char	*treat_precision(char *str, t_specs opt, char c)
{
	int	*tab;

	tab = (int*)malloc(sizeof(int) * 2);
	tab[0] = 0;
	tab[1] = 0;
	if (!verif_str("eEfFgGaAmtqbsSpdDioOuUxXcC", c) || opt.precision == -1)
		return (str);
	if ((c == 'O' || c == 'o') && opt.precision == 0 &&
			!ft_strcmp(str, "0") && opt.flags & 0x10)
		return ("0");
	if (c != 'c' && opt.precision == 0 && !ft_strcmp(str, "0"))
		return ("");
	if (c == 'p' || (opt.flags & 0x10 && (str[1] == 'x' || str[1] == 'X')))
	{
		if (str[1] != 'x' && str[1] != 'X')
			str[1] = '0';
		if (opt.precision != 2)
			opt.precision = opt.precision + 2;
		tab[1] = 1;
	}
	str = treat_precision2(str, opt, c, &tab);
	str = treat_precision1(str, opt, c, tab);
	return (str);
}

char	*treat_options(char *str, t_specs opt, char c, int z)
{
	str = treat_precision(str, opt, c);
	str = treat_flag_plus(str, opt, c);
	str = treat_flag_space(str, opt, c);
	str = treat_largeur(str, opt, c, z);
	return (str);
}
