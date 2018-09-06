/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 20:06:22 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/04 20:28:59 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*initial(t_fdf *m)
{
	m->ptr = NULL;
	m->window = NULL;
	m->col = 0;
	m->row = 0;
	m->hy = 0;
	m->wx = 0;
	m->h = 1;
	m->dx = 0;
	m->dy = 0;
	return (m);
}

void	formulas(t_fdf *m)
{
	m->dx = SIZE / (2 * m->col);
	if (m->dx < 5)
		m->dx = 5;
	m->dy = (int)(m->dx * 0.4);
	m->wx = (SIZE / 2 - abs(m->col - m->row) / 2 * m->dx) - m->dx;
	m->hy = SIZE / 2 - abs(m->col - m->row) * m->dy;
	m->val = (int**)malloc(sizeof(int*) * (m->row));
}

void	verify_map(t_fdf *m, char *line)
{
	if (m->row == 1)
		m->col = count_words(line, ' ');
	else if (count_words(line, ' ') != m->col)
	{
		ft_printf("Oh oh Error3!\n");
		exit(-1);
	}
}

t_fdf	*readfile(t_fdf *m, char *arg, int i, int fd)
{
	char	*line;

	m = initial(m);
	if ((fd = open(arg, O_RDONLY)) < 0)
		return (m);
	while (get_next_line(fd, &line) > 0)
	{
		m->row += 1;
		verify_map(m, line);
		ft_memdel((void**)&line);
	}
	close(fd);
	if (m->col == 0)
		if (ft_printf("Oh oh Error4!\n"))
			exit(-1);
	formulas(m);
	if ((fd = open(arg, O_RDONLY)) < 0)
		return (m);
	while (get_next_line(fd, &line) > 0)
	{
		m->val[i++] = ft_nbrsplit(line, ' ');
		ft_memdel((void**)&line);
	}
	return (m);
}
