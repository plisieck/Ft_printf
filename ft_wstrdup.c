/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 18:49:07 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 18:49:08 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ft_wstrdup(wchar_t *s1)
{
	size_t	len;
	wchar_t	*s2;

	if (!s1)
		return (L"(null)");
	len = ft_wstrlen(s1);
	s2 = (wchar_t *)malloc(sizeof(wchar_t) * len + 1);
	if (!s2)
		return (L"(null)");
	len = 0;
	while (s1[len] != '\0')
	{
		s2[len] = s1[len];
		len++;
	}
	s2[len] = '\0';
	return (s2);
}
