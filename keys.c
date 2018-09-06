/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 13:49:52 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/05 18:57:36 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_instructions(void *ptr, void *window)
{
	mlx_string_put(ptr, window, 1, 51, 16751001,
			"Zoom in / Zoom out = \"+ / -\"");
	mlx_string_put(ptr, window, 1, 70, 16751001,
			"Move up / Move down = \"up / down\"");
	mlx_string_put(ptr, window, 1, 90, 16751001,
			"Move left / Move right = \"left / right\"");
	mlx_string_put(ptr, window, 1, 110, 16751001,
			"Increase / Decrease height = \"h / l\"");
	mlx_string_put(ptr, window, 1, 130, 16751001,
			"Change the color = \"c\"");
	mlx_string_put(ptr, window, 1, 150, 16751001,
			"Exit = \"ESC\"");
}

void	esc(t_fdf *m)
{
	while (m->row--)
		ft_memdel((void**)&m->val[m->row]);
	ft_memdel((void**)&m->val);
	exit(-1);
}

int		keyboard(int key, t_fdf *m)
{
	mlx_clear_window(m->ptr, m->window);
	(key == 125) ? m->hy += m->dy : 0;
	(key == 126) ? m->hy -= 5 * m->dy : 0;
	(key == 123) ? m->wx -= m->dx / 2 : 0;
	(key == 124) ? m->wx += m->dx / 2 : 0;
	(key == 53) ? esc(m) : 0;
	(key == 4) ? m->h += 1 : 0;
	(key == 37) ? m->h -= 1 : 0;
	if (key == 24 || key == 69)
	{
		m->dx += 5;
		m->dy += 5;
	}
	else if (key == 27 || key == 78)
	{
		m->dx -= 1;
		m->dy -= 1;
	}
	else if (key == 8)
		m->c += (m->c < 100) ? 1 : -99;
	drawmap(m);
	return (0);
}

int		mouse(int key, int x, int y, t_fdf *m)
{
	mlx_clear_window(m->ptr, m->window);
	if (key == 4)
		m->h += 1;
	else if (key == 5)
		m->h -= 1;
	else if (key == 1)
	{
		m->wx = x - m->dx - (m->col - m->row) / 2 * m->dx;
		m->hy = y - m->row * m->dy + (m->row - m->col) / 2 * m->dy;
	}
	drawmap(m);
	return (0);
}
