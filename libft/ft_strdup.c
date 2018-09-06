/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 20:06:20 by apetrech          #+#    #+#             */
/*   Updated: 2018/06/22 19:44:14 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *tmp;

	tmp = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (tmp == NULL)
		return (NULL);
	ft_strcpy(tmp, src);
	return (tmp);
}
