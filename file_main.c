/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:34:03 by jchardin          #+#    #+#             */
/*   Updated: 2019/05/27 16:16:57 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

typedef struct					s_myvec
{
	float						x;
	float						y;
	float						z;
	struct s_myvec				*next;
}								t_myvec;

//indice allow you to build multiple triangles using share vectices
typedef struct			s_mypolygon
{
	t_myvec				*vertex_lst;             //liste des vertex
	t_myvec				normal;                   //la normal au polygon
	int					number_of_vertex;       //nombre de vertex
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
	t_mypolygon			*polygon_lst;

}						t_mywin;

t_myvec			*ft_get_and_create_vertex_node(char *line, int *j)
{
	int			k;
	char		nbr[100];
	t_myvec		*s_vertex;

	s_vertex = (t_myvec*)malloc(sizeof(t_myvec));
		k = 0;
	while(ft_isdigit(line[*j]) || line[*j] == '-' )
	{
		nbr[k] = line[*j];
		*j = *j + 1;
		k++;
	}
	nbr[k] = '\0';
	s_vertex->x = ft_atoi(nbr);

		k = 0;
		*j = *j + 1;
	while(ft_isdigit(line[*j]) || line[*j] == '-' )
	{
		nbr[k] = line[*j];
		*j = *j + 1;
		k++;
	}
	nbr[k] = '\0';
	s_vertex->y = ft_atoi(nbr);

		k = 0;
		*j = *j + 1;
	while(ft_isdigit(line[*j]) || line[*j] == '-' )
	{
		nbr[k] = line[*j];
		*j = *j + 1;
		k++;
	}
	nbr[k] = '\0';
	s_vertex->z = ft_atoi(nbr);
	return (s_vertex);
}

void			ft_add_vertex(t_myvec **vertex_lst, t_myvec *vertex_node)
{
	if (*vertex_lst == NULL)
	{
		vertex_node->next = NULL;
		*vertex_lst = vertex_node;
	}
	else
	{
		vertex_node->next = *vertex_lst;
		*vertex_lst = vertex_node;
	}
}

void			ft_go_to_first_vertex(char *line, int *j)
{
	while(line[*j] != ':' )
	{
		*j = *j + 1;
	}
	*j = *j + 1;
}

t_mypolygon	*ft_create_polygon_node(t_myvec *vertex_lst)
{
	t_mypolygon	*polygon_node;

	polygon_node = (t_mypolygon*)malloc(sizeof(t_mypolygon));
	polygon_node->vertex_lst = vertex_lst;
	return(polygon_node);
}

void	ft_add_polygon(t_mypolygon **polygon_lst, t_mypolygon *polygon_node)
{
	if (*polygon_lst == NULL)
	{
		polygon_node->next = NULL;
		*polygon_lst = polygon_node;
	}
	else
	{
		polygon_node->next = *polygon_lst;
		*polygon_lst = polygon_node;
	}
}

t_mypolygon		*ft_read_the_polygon_file(void)
{
	int				fd;
	char			*line;
	t_myvec			*vertex_node;
	t_myvec			*vertex_lst;
	t_mypolygon		*polygon_node;
	t_mypolygon		*polygon_lst;
	int				j;

	line = NULL;
	polygon_lst = NULL;
	fd = open("./file_wall", O_RDWR);
	while(get_next_line(fd, &line))
	{
		j = 0;
		vertex_lst = NULL;
		ft_go_to_first_vertex(line, &j);
		while(line[j] != ':' && line[j] != '\0')
		{
			vertex_node = ft_get_and_create_vertex_node(line, &j);
			ft_add_vertex(&vertex_lst, vertex_node);
			if (line[j] != ':')
				j++;
		}
		polygon_node = ft_create_polygon_node(vertex_lst);
		ft_add_polygon(&polygon_lst, polygon_node);
	}
	return (polygon_lst);
}

void	ft_display_the_polygon_list(t_mypolygon *polygon_lst)
{
	t_mypolygon		*keep;
	t_myvec			*keep_vec;
	int				i;
	int				j;

	keep = polygon_lst;
	printf("Display polygone lst\n");
	i = 0;
	while (polygon_lst != NULL)
	{
		printf("\n\nPolynome n=%d\n", i);
		keep_vec = polygon_lst->vertex_lst;
		j = 0;
		while (polygon_lst->vertex_lst != NULL)
		{
			printf("vertice n=%d\n", j);
			printf("x =%f\n", polygon_lst->vertex_lst->x);
			printf("y =%f\n", polygon_lst->vertex_lst->y);
			printf("z =%f\n", polygon_lst->vertex_lst->z);
			j++;
			polygon_lst->vertex_lst = polygon_lst->vertex_lst->next;
		}
		polygon_lst->vertex_lst = keep_vec;
		polygon_lst = polygon_lst->next;
		i++;
	}
	polygon_lst = keep;
}

int		main(void)
{
	t_mywin		s_win;

	printf("hello chef Inca\n");
	s_win.polygon_lst = ft_read_the_polygon_file();
	ft_display_the_polygon_list(s_win.polygon_lst);
	return (1);
}
