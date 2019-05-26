/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:34:03 by jchardin          #+#    #+#             */
/*   Updated: 2019/05/26 16:43:58 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

typedef struct					s_myvec
{
	float						x;
	float						y;
	float						z;
}								t_myvec;

//indice allow you to build multiple triangles using share vectices
typedef struct			s_mypolygon
{
	t_myvec				*vertex_list;             //liste des vertices
	t_myvec				normal;                   //la normal au polygone
	int					number_of_vertices;       //nombre de vertices
	int					number_of_indices;        //nombre d'indices
	int					*indices;                 //la listes des indices apres triangulasisation
	struct s_mypolygon	*next;                    //le prochain noeud dans la liste
}						t_mypolygon;

//structure pour le bsp
typedef struct			s_mynode
{
	t_mypolygon			*splitter;
	struct s_mynode		*front;
	struct s_mynode		*back;
	char				is_leaf;
	char				is_solid;
}						t_mynode;

//structure principale
typedef struct			s_mywin
{
	t_mypolygon			s_polygon;

}						t_mywin;

t_mypolygon		ft_read_the_polygon_file(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("./file_wall", O_RDWR);
	while(get_next_line(fd, &line))
	{


	}

}

void	ft_display_the_polygon_list(void)
{

}

int		main(void)
{
	t_mywin		s_win;

	s_win.s_polygon = ft_read_the_polygon_file();
	ft_display_the_polygon_list();



	t_mypolygon		*s_polygon_lst;
	t_mypolygon		*node_polygon;


	s_polygon_lst = NULL;               //this is the global pointer
	node_polygon = NULL;






	return (1);
}
