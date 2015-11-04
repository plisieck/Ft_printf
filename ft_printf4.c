/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 20:52:56 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/07 21:18:41 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t *ft_wstrnew(size_t size)
{
	wchar_t *adr;

	if (size >= 4294967296)
		return (NULL);
	adr = (wchar_t *)malloc(sizeof(wchar_t) * size + 1);
	if (!adr)
		return (NULL);
	return (adr);
}

wchar_t *ft_wstrsub(wchar_t *s, unsigned int start, size_t len)
{
	wchar_t	*str;

	str = ft_wstrnew(len);
	if (!str || !s)
		return (NULL);
	str = ft_wstrncpy(str, &s[start], len);
	return (str);
}

int		*init_tab(void)
{
	int	*tab;

	tab = (int*)malloc(sizeof(int) * 5);
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	return (tab);
}

int		*asign_tab(int *tab, t_specs opt, char *str)
{
	if (ft_strlen(str) < (unsigned int)opt.precision)
	{
		if (str[0] == '-')
			tab[0] = 1;
		else if (str[0] == ' ')
			tab[1] = 1;
		else if (str[0] == '+')
			tab[2] = 1;
		else if (str[1] == 'x')
		{
			str[1] = '0';
			tab[3] = 1;
		}
	}
	return (tab);
}

char	*treat_flag_plus(char *str, t_specs opt, char c)
{
	if (c != 'd' && c != 'D' && c != 'i')
		return (str);
	if (str[0] != '-' && opt.flags & 0x02)
		str = ft_strjoin("+", str);
	return (str);
}
