/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bsp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:51:31 by jchardin          #+#    #+#             */
/*   Updated: 2019/05/27 17:57:07 by jchardin         ###   ########.fr       */
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
	t_myvec				normal;                  //la normal au polygon
	int					number_of_vertex;        //nombre de vertex
	int					number_of_indices;       //nombre d'indices
	int					*indices;                //la listes des indices apres triangulasisation
	struct s_mypolygon	*next;                   //le prochain noeud dans la liste
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



void			ft_display_the_polygon_list(t_mypolygon *polygon_lst);
t_mypolygon		*ft_read_the_polygon_file(void);