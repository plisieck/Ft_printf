/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 20:33:53 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 17:32:48 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_specs	split_check_options(va_list ap, const char *format, t_specs opt, int *i)
{
	if (verif_str("#0-+ ", format[*i]))
		check_flags(format, i, &opt.flags);
	else if (verif_str("0123456789", format[*i]) ||
			(format[*i] == '*' && format[*i - 1] != '.'))
		opt.largeur = check_larg(ap, format, i, &opt.flags);
	else if (format[*i] == '.')
	{
		(*i)++;
		opt.precision = 0;
		opt.precision = check_precision(ap, format, i);
	}
	else if (verif_str("hljz", format[*i]))
		check_modificator(format, i, &opt.modif);
	return (opt);
}

t_specs check_options(va_list ap, const char *format, int *i)
{
	t_specs opt;

	(*i)++;
	opt = init_structure(opt);
	while (!verif_str("eEfFgGaAmtqbsSpdDioOuUxXcC", format[*i]))
	{
		if (verif_str("#0-+ ", format[*i]) ||
				verif_str("0123456789", format[*i]) ||
				verif_str("hljz", format[*i]) ||
				format[*i] == '.' || format[*i] == '*')
			opt = split_check_options(ap, format, opt, i);
		else
			break ;
	}
	return (opt);
}

wchar_t	*wtreat_largeur2(wchar_t *wstr, t_specs opt, int z)
{
	while (ft_wstrlen(wstr) + z < (unsigned int)opt.largeur)
	{
		if (opt.flags & 0x08)
			wstr = ft_wstrjoin(L"0", wstr);
		else
		{
			if (!(opt.flags & 0x04))
				wstr = ft_wstrjoin(L" ", wstr);
			else
				wstr = ft_wstrjoin(wstr, L" ");
		}
	}
	return (wstr);
}

wchar_t	*wtreat_larg3(wchar_t *wstr, t_specs opt, int octal, int neg)
{
	if ((octal || neg) && opt.flags & 0x08)
	{
		if (neg == 1)
			wstr[0] = '-';
		if (octal == 1)
			wstr[1] = 'x';
	}
	return (wstr);
}

wchar_t *wtreat_largeur(wchar_t *wstr, t_specs opt, int z)
{
	int	neg;
	int octal;

	if (ft_wstrlen(wstr) > (unsigned int)opt.largeur)
		return (wstr);
	neg = 0;
	octal = 0;
	if (opt.flags & 0x08 && (wstr[0] == '-' || wstr[1] == 'x'))
	{
		if (wstr[0] == '-')
		{
			neg = 1;
			wstr++;
		}
		if (wstr[1] == 'x')
		{
			octal = 1;
			wstr[1] = 0;
		}
	}
	wstr = wtreat_largeur2(wstr, opt, z);
	wstr = wtreat_larg3(wstr, opt, octal, neg);
	return (wstr);
}
