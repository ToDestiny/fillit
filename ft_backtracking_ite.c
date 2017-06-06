/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking_ite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:45:43 by llorgere          #+#    #+#             */
/*   Updated: 2017/06/06 18:55:25 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"
#include <stdio.h>

int		ft_backtracking_ite(char **square, int sq_s, int ***tetra, int nb_tetra)
{
	t_type type;
	int		i;

	printf("test backtrack 1\n");
	type.pos = 0;
	i = 0;
	while (i < nb_tetra)
	{
		printf("test backtrack 2\n");
		type.row = type.pos / sq_s;
		type.col = type.pos % sq_s;
		printf ("row est %d et col est %d et i est %d\n", type.row, type.col, i);
		if (ft_check_posi(square, tetra[i], type.pos, sq_s) == 1)
		{
			type.test = 0;
			printf("test backtrack 3\n");
			square = ft_put_tetra(square, tetra[i], type.row, type.col, i);
			printf("i:%d type.pos:%d\n", i, type.pos);
			type.pos_tet[i] = type.pos;
			printf("type.pos_tet[%d]:%d\n", i, type.pos_tet[i]);
			type.pos = 0;
			i++;
			printf("test backtrack 3.5\n");
		}
		else if (ft_check_posi(square, tetra[i], type.pos, sq_s) == 0 && type.pos != (sq_s * sq_s) - 1)
		{
			printf("test backtrack 4\n");
			type.pos++;
		}
		else if (ft_check_posi(square, tetra[i], type.pos, sq_s) == 0 && type.pos == (sq_s * sq_s) - 1)
		{
			printf("test backtrack 5\n");
			printf("test i--");
			if (i ==  0)
				return (-1);
			i--;
			type.pos = type.pos_tet[i];
			printf("test pos");
			square = ft_rm_tetra(square, tetra[i], type.row, type.col);
			type.pos++;
		}
	}
	for (int j = 0;j < 4;j++)
		printf("square[%d]:%s", j, square[j]);
	return (1);
}
