/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 08:52:01 by jchardin          #+#    #+#             */
/*   Updated: 2019/05/28 08:14:41 by pi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (s == 0)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
