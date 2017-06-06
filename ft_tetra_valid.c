/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetra_$.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:08:15 by llorgere          #+#    #+#             */
/*   Updated: 2017/06/06 14:54:41 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libfil.h"
#define BUFF_SIZE 21

char	**ft_tetra_valid(char *file, int n)
{
	int		fd;
	char	buff[BUFF_SIZE + 1];
	char	**tab;
	int		i;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * ((n - 20) / 21 + 1))))
		return (NULL);
	i = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		printf("ret is:%di\tbuff[21]:%c\n", ret, buff[21]);
		buff[21] = '\0';
		if (buff[20] == '\n' && i == (n - 20) / 21)
			return (NULL);
		else if (ft_check_tetra(buff) == 1)
		{
			tab[i] = ft_strdup(buff);
//			printf("tab[%d] est %s", i, tab[i]);
			i++;
		}
		else
			return (NULL);
		ft_bzero(buff, 22);
		printf("END READ boucle\n");
	}
	close(fd);
	printf("close\n");
	return (tab);
}
