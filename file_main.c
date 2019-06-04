/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:34:03 by jchardin          #+#    #+#             */
/*   Updated: 2019/06/04 15:06:59 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bsp.h"
#include <math.h>

void		ft_browse_the_bsp(t_mynode *s_node, char **tab,int decalage_pere, int decalage, int rang, int profondeur_max)
{
	int middle = 26;
	char		*value;


	value = ft_itoa((int)s_node->splitter->number_of_vertex);
	tab[rang][middle + decalage + decalage_pere] = value[0];


	decalage_pere = decalage + decalage_pere;


	if (s_node->front->is_leaf != TRUE)
		ft_browse_the_bsp(s_node->front, tab, decalage_pere, pow(2, profondeur_max - (rang + 1)) ,  rang + 1, profondeur_max);


	if (s_node->back->is_leaf != TRUE)
		ft_browse_the_bsp(s_node->back, tab, decalage_pere, -pow(2, profondeur_max - (rang + 1)) ,  rang + 1, profondeur_max);
}

void		ft_display_the_bsp(t_mynode *s_node, char **tab)
{
	int i, j;

	i = j = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void		ft_init_tab(char ***tab)
{
	int i, j;

	i = j = 0;
	*tab = (char**)malloc(sizeof(char*) * 51);
	while (i < 50)
	{
		(*tab)[i] = (char*)malloc(sizeof(char) * 50 );
		j = 0;
		while (j < 50)
		{
			(*tab)[i][j] = '_';
			j++;
		}
		printf("\n");
		i++;
	}
}

int			main(void)
{
	t_mywin		s_win;
	t_mynode	s_node;
	char		**tab;
	int			decalage = 0;
	int			profondeur_maxi = 4;



	printf("hello chef Inca\n");
	s_win.polygon_lst = ft_read_the_polygon_file();
	ft_display_the_polygon_list(s_win.polygon_lst);
	ft_process_polygon(s_win.polygon_lst);
	ft_build_bsp_tree((&s_node), s_win.polygon_lst);

	ft_init_tab(&tab);
	ft_browse_the_bsp(&s_node, tab,0, decalage, 0, profondeur_maxi);
	ft_display_the_bsp(&s_node, tab);


	return (1);
}
