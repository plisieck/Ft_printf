/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 14:49:15 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 17:42:00 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrjoin(char *s1, char *s2, int pos)
{
	int		i;
	int		j;
	char	*str;
	int		cut;

	str = (char *)malloc(sizeof(int) * ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (i < pos)
	{
		str[i] = s1[i];
		i++;
	}
	cut = i;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	while (s1[cut] != '\0')
		str[i++] = s1[cut++];
	str[i] = '\0';
	return (str);
}
