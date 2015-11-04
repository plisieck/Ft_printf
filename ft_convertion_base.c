/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 18:45:51 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 18:45:53 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convertion_base(int base, unsigned long long int nb, char *t, int s)
{
	long long int tp2;

	tp2 = nb % base;
	nb /= base;
	if (tp2 > 9)
	{
		t = (tp2 == 10 && s & 0x01 ? ft_strjoin("A", t) : ft_strjoin("", t));
		t = (tp2 == 11 && s & 0x01 ? ft_strjoin("B", t) : ft_strjoin("", t));
		t = (tp2 == 12 && s & 0x01 ? ft_strjoin("C", t) : ft_strjoin("", t));
		t = (tp2 == 13 && s & 0x01 ? ft_strjoin("D", t) : ft_strjoin("", t));
		t = (tp2 == 14 && s & 0x01 ? ft_strjoin("E", t) : ft_strjoin("", t));
		t = (tp2 == 15 && s & 0x01 ? ft_strjoin("F", t) : ft_strjoin("", t));
		t = (tp2 == 10 && !s & 0x01 ? ft_strjoin("a", t) : ft_strjoin("", t));
		t = (tp2 == 11 && !s & 0x01 ? ft_strjoin("b", t) : ft_strjoin("", t));
		t = (tp2 == 12 && !s & 0x01 ? ft_strjoin("c", t) : ft_strjoin("", t));
		t = (tp2 == 13 && !s & 0x01 ? ft_strjoin("d", t) : ft_strjoin("", t));
		t = (tp2 == 14 && !s & 0x01 ? ft_strjoin("e", t) : ft_strjoin("", t));
		t = (tp2 == 15 && !s & 0x01 ? ft_strjoin("f", t) : ft_strjoin("", t));
	}
	else
		t = ft_strjoin(ft_itoa(tp2), t);
	return ((nb > 0 ? convertion_base(base, nb, t, s) : t));
}
