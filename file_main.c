/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:34:03 by jchardin          #+#    #+#             */
/*   Updated: 2019/05/27 11:01:15 by jchardin         ###   ########.fr       */
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
	t_myvec				*vertex_lst;             //liste des vertex
	t_myvec				normal;                   //la normal au polygone
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
	t_mypolygon			polygon_lst;

}						t_mywin;

t_myvec			*ft_get_and_create_vertex(char *line, int *j)
{
	int			k;
	int			nbr[100];
	t_myvec		*s_vertex;

	s_vertex = (t_myvec*)malloc(sizeof(t_myvec));
	*j = *j + 1;
	while(ft_isdigit(line[*j]) || line[*j] == '-' )
	{
		k = 0;
		nbr[k] = line[*j];
		*j = *j + 1;
		k++;
	}
	s_vertex->x = ft_atoi(nbr);
	*j = *j + 1;

	while(ft_isdigit(line[*j]) || line[*j] == '-' )
	{
		k = 0;
		nbr[k] = line[*j];
		*j = *j + 1;
		k++;
	}
	s_vertex->y = ft_atoi(nbr);
	*j = *j + 1;

	while(ft_isdigit(line[*j]) || line[*j] == '-' )
	{
		k = 0;
		nbr[k] = line[*j];
		*j = *j + 1;
		k++;
	}
	s_vertex->z = ft_atoi(nbr);
	return (s_vertex);
}

void			ft_add_vertice(t_myvec **vertex_lst, t_myvec *vertex_node)
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

void			ft_go_to_first_vertice(char *line, int *j)
{
	while(line[*j] != ':' )
		*j = *j + 1;
}

t_mypolygone	*ft_create_polygone_node(t_vec *vertex_lst)
{
	t_mypolygone	*polygone_node;

	polygone_node = (t_mypolygone*)malloc(sizeof(t_mypolygone));
	polygone_node->vertex_lst = vertex_lst;
	return(polygone_node);
}

void	ft_add_polygone(t_mypolygone **polygone_lst, t_mypolygone *polygone_node)
{
	if (*polygone_lst == NULL)
	{
		polygone_node->next = NULL;
		*polygone_lst = polygone_node;
	}
	else
	{
		polygone_node->next = *polygone_lst;
		*polygone_lst = polygone_node;
	}
}

t_mypolygon		ft_read_the_polygon_file(void)
{
	int				fd;
	char			*line;
	t_myvec			*vertex_node;
	t_myvec			*vertex_lst;
	t_mypolygon		*polygon_node;
	t_mypolygon		*polygon_lst;
	int				j;

	line = NULL;
	vertex_lst = NULL;
	polygon_lst = NULL;
	fd = open("./file_wall", O_RDWR);
	while(get_next_line(fd, &line))
	{
		j = 0;
		ft_go_to_first_vertice(line, &j);
		while(line[j] != ':')
		{
			vertex_node = ft_get_and_create_vertex_node(line, &j);
			ft_add_vertex(&vertex_lst, vertex_node);
		}
		polygone_node = ft_create_polygone_node(t_myvec *vertex_lst);
		ft_add_polygone(&polygon_lst, polygon_node);
	}
	return (polygon_lst);
}

void	ft_display_the_polygon_list(t_mypolygon *polygon_lst)
{
	t_mypolygon		*keep;

	keep = polygone_lst;
	while(polygone_lst != NULL)
	{
		printf("first verrtice =%d\n", polygon_lst->);
		polygone_lst = polygon->next;
	}
	polygone_lst = keep;
}

int		main(void)
{
	t_mywin		s_win;

	printf("hello chef Inca\n");
	s_win.polygon_lst = ft_read_the_polygon_file();
	ft_display_the_polygon_list(s_win.polygon_lst);
	return (1);
}
