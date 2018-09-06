/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:01:31 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/05 18:52:49 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf m;

	if (ac >= 2)
	{
		m = *readfile(&m, av[1], 0, 0);
		if (m.row == 0)
		{
			ft_printf("Oh oh Error1!\n");
			exit(-1);
		}
		m.ptr = mlx_init();
		m.window = mlx_new_window(m.ptr, SIZE, SIZE, "window");
		drawmap(&m);
		mlx_key_hook(m.window, keyboard, &m);
		mlx_mouse_hook(m.window, mouse, &m);
		mlx_loop(m.ptr);
	}
	else
	{
		ft_printf("Oh oh Error2!\n");
		exit(-1);
	}
}
