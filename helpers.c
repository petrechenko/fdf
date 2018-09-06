/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:17:29 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/05 18:50:01 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_words(char *line, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (line[i])
	{
		if (line[i] != c && (i == 0 || line[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

int	*fill(char *s, char c, int *split, size_t words)
{
	size_t	i;
	int		j;
	char	*temp;

	i = -1;
	temp = (char*)s;
	while (++i < words)
	{
		j = 0;
		split[i] = ft_atoi((char*)(temp + j));
		while (temp[j] == c)
			j++;
		temp = strchr(temp + j, c);
	}
	return (split);
}

int	*ft_nbrsplit(char *s, char c)
{
	size_t	words;
	int		*split;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (NULL == (split = (int*)malloc(sizeof(int) * words)))
		return (NULL);
	return (fill(s, c, split, words));
}
