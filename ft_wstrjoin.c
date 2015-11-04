/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:07:28 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 18:49:13 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t *ft_wstrjoin(wchar_t *s1, wchar_t *s2)
{
	int		i;
	int		j;
	wchar_t	*str;

	i = ft_wstrlen(s1);
	i += ft_wstrlen(s2);
	j = 0;
	str = (wchar_t *)malloc(sizeof(wchar_t) * (i + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[j++] = *s1++;
	while (*s2)
		str[j++] = *s2++;
	str[j] = '\0';
	return (str);
}
