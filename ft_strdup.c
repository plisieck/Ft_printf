/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 18:47:52 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 18:47:54 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	if (!s1)
		return ("(null)");
	s2 = (char *)malloc(sizeof(char *) * len + 1);
	if (s2 == NULL)
		return (s2);
	len = 0;
	while (s1[len] != '\0')
	{
		s2[len] = s1[len];
		len++;
	}
	s2[len] = '\0';
	return (s2);
}
