/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 18:48:48 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 18:48:50 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar4(wchar_t c, int tab[4])
{
	tab[0] |= 0xC0;
	tab[0] |= (c >> 6);
	tab[1] |= 0x80;
	tab[1] |= (c & 0x3F);
}

static void	ft_wputchar3(wchar_t c, int tab[4])
{
	tab[0] |= 0xE0;
	tab[0] |= (c >> 12);
	tab[1] |= 0x80;
	tab[1] |= ((c >> 6) & 0x3F);
	tab[2] |= 0x80;
	tab[2] |= (c & 0x3F);
}

static void	ft_wputchar2(wchar_t c, int tab[4])
{
	tab[0] |= 0xF0;
	tab[0] |= (c >> 18);
	tab[1] |= 0x80;
	tab[1] |= ((c >> 12) & 0x3F);
	tab[2] |= 0x80;
	tab[2] |= ((c >> 6) & 0x3F);
	tab[3] |= 0x80;
	tab[3] |= (c & 0x3f);
}

void		ft_wputchar(wchar_t c)
{
	int nb;
	int tab[4];
	int i;

	i = 0;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	nb = ft_strlen(convertion_base(2, c, "", 0));
	if (nb <= 7)
		tab[0] = (char)c;
	else if (nb <= 11)
		ft_putchar4(c, tab);
	else if (nb <= 16)
		ft_wputchar3(c, tab);
	else
		ft_wputchar2(c, tab);
	while (tab[i])
		write (1, &tab[i++], 1);
}
