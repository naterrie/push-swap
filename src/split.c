/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:56:42 by naterrie          #+#    #+#             */
/*   Updated: 2023/02/23 10:02:17 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../SwapPush.h"

static size_t	count_str(char const *s, char c)
{
	size_t	nbstr;
	size_t	i;

	nbstr = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			nbstr++;
		}
		else
			i++;
	}
	return (nbstr);
}

static const char	*dup_until_c(char **dest, char const *src, char c)
{
	size_t	len;
	size_t	i;

	while (*src == c)
		src++;
	len = 0;
	while (src[len] != '\0' && src[len] != c)
		len++;
	*dest = (char *)malloc(sizeof(char) * (len + 1));
	if (*dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		(*dest)[i] = src[i];
		i++;
	}
	(*dest)[i] = '\0';
	src += len + 1;
	return (src);
}

static void	free_str(char ***str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
	*str = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	nbstr;

	if (!s)
		return (NULL);
	nbstr = count_str(s, c);
	str = (char **)malloc(sizeof(char *) * (nbstr + 1));
	if (str)
	{
		str[nbstr] = NULL;
		i = 0;
		while (i < nbstr)
		{
			s = dup_until_c(str + i, s, c);
			if (s == NULL)
			{
				free_str(&str, i);
				return (str);
			}
			i++;
		}
	}
	return (str);
}