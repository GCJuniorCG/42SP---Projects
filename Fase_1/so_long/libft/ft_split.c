/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:30:17 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:30:18 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft__gtoken_size(const char *s, const char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static size_t	ft__gntokens(const char *s, const char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			n++;
		while (s[i] != c && s[i])
			i++;
	}
	return (n);
}

static char	*ft__newstr(size_t size)
{
	char	*p;

	p = (char *)ft_calloc((size + 1), sizeof(char));
	if (!p)
		return (NULL);
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**token;
	size_t	i;
	size_t	j;
	size_t	k;

	token = (char **)ft_calloc((ft__gntokens(s, c) + 1), sizeof(*token));
	if (!token)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft__gntokens(s, c))
	{
		k = 0;
		token[i] = ft__newstr(ft__gtoken_size((s + j), c));
		if (!token[i])
			token[i] = NULL;
		while (*(s + j) == c)
			j++;
		while (*(s + j) != c && *(s + j))
			token[i][k++] = s[j++];
		i++;
	}
	return (token);
}
