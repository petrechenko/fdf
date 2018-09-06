/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:52:31 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/05 18:48:55 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define SIZE 1000

typedef struct	s_fdf
{
	void		*ptr;
	void		*window;
	int			col;
	int			row;
	int			hy;
	int			wx;
	int			h;
	int			c;
	int			dx;
	int			dy;
	int			**val;
}				t_fdf;

int				*newline(int x0, int x1, int y0, int y1);
void			small_angle(t_fdf *m, int *line, float s, int col);
void			big_angle(t_fdf *m, int *line, float s, int col);
void			drawline(t_fdf *m, int *line, int col);
void			drawmap(t_fdf *m);

t_fdf			*initial(t_fdf *m);
void			formulas(t_fdf *m);
void			verify_map(t_fdf *m, char *line);
t_fdf			*readfile(t_fdf *m, char *arg, int i, int fd);

void			draw_instructions(void *ptr, void *window);
int				mouse(int key, int x, int y, t_fdf *m);
int				keyboard(int key, t_fdf *m);
void			esc(t_fdf *m);

int				count_words(char *line, char c);
int				*fill(char *s, char c, int *split, size_t words);
int				*ft_nbrsplit(char *s, char c);

int				main(int ac, char **av);

#endif
