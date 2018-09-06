/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:47:44 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/04 19:52:08 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define X(i, j, b, s) j * b + s - (b * i)
#define Y(i, j, b, s) (i + j) * b + s
#define C(x, y) 9056567 - abs(x * y * 2000)

int		*newline(int x0, int x1, int y0, int y1)
{
	int	*line;

	if ((line = (int*)malloc(sizeof(int) * 4)) == NULL)
		return (NULL);
	line[0] = x0;
	line[1] = x1;
	line[2] = y0;
	line[3] = y1;
	return (line);
}

void	small_angle(t_fdf *m, int *line, float s, int col)
{
	float	c;
	int		neg;

	c = 0;
	neg = 1;
	if (s < 0)
		neg = -1;
	while (line[0] < line[1])
	{
		c += s * neg;
		if (c > 0.5)
		{
			line[2] += neg;
			c--;
		}
		mlx_pixel_put(m->ptr, m->window, line[0]++, line[2], C(col, m->c));
	}
}

void	big_angle(t_fdf *m, int *line, float s, int col)
{
	float	c;
	int		neg;

	c = 0;
	neg = 1;
	if (s < 0)
		neg = -1;
	while (line[2] < line[3])
	{
		c += 1 / s * neg;
		if (c > 0.5)
		{
			line[0] += neg;
			c--;
		}
		mlx_pixel_put(m->ptr, m->window, line[0], line[2]++, C(col, m->c));
	}
}

void	drawline(t_fdf *m, int *line, int col)
{
	float	s;
	int		temp;

	s = (float)(line[3] - line[2]) / (line[1] - line[0]);
	if ((line[3] - line[2] < 0 && (s) > 1) ||
			(line[1] - line[0] < 0 && (s) < 1))
	{
		temp = line[3];
		line[3] = line[2];
		line[2] = temp;
		temp = line[1];
		line[1] = line[0];
		line[0] = temp;
	}
	if (line[0] == line[1])
	{
		while (line[2] < line[3])
			mlx_pixel_put(m->ptr, m->window, line[0], line[2]++, C(col, m->c));
		return ;
	}
	if (line[3] - line[2] < line[1] - line[0])
		small_angle(m, line, s, col);
	else
		big_angle(m, line, s, col);
	free(line);
}

void	drawmap(t_fdf *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->row)
	{
		j = 0;
		while (++j < m->col + 1)
		{
			if (j < m->col)
				drawline(m, newline(X(i, j, m->dx, m->wx),
					X(i, (j + 1), m->dx, m->wx),
					Y(i, j, m->dy, m->hy - m->val[i][j - 1] * m->h),
					Y(i, (j + 1), m->dy, m->hy - m->val[i][j] * m->h)),
					m->val[i][j] + m->val[i][j - 1]);
			if (i < m->row - 1)
				drawline(m, newline(X(i, j, m->dx, m->wx),
					X((i + 1), j, m->dx, m->wx),
					Y(i, j, m->dy, m->hy - m->val[i][j - 1] * m->h),
					Y(i, (j + 1), m->dy, m->hy - m->val[i + 1][j - 1] * m->h)),
					m->val[i][j - 1] + m->val[i + 1][j - 1]);
		}
	}
	draw_instructions(m->ptr, m->window);
}
