/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:34:03 by jchardin          #+#    #+#             */
/*   Updated: 2019/05/28 14:25:28 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bsp.h"

void			ft_display_the_polygon_list(t_mypolygon *polygon_lst)
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

t_myvec		ft_cross_product(t_myvec v1, t_myvec v2)
{
	t_myvec		result;

	result.x = (v1.y * v2.z) - (v1.z * v2.y);
	result.y = (v1.z * v2.x) - (v1.x * v2.z);
	result.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (result);
}

//ok
float		ft_dot_product(t_myvec v1, t_myvec v2)
{
	float		result;
	result = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	return (result);
}

t_myvec		ft_calculate_polygon_normal(t_mypolygon *polygon_node)
{
	t_myvec		normal;

	normal.x = 0;
	normal.y = 0;
	normal.z = 0;
	(void)polygon_node;

	printf ("x=%f, y=%f, z=%f\n", normal.x, normal.y, normal.z);
	return (normal);
}

int			ft_calculate_number_of_vertex(t_mypolygon *polygon_node)
{
	int		number_of_vertex;

	number_of_vertex = 0;
	(void)polygon_node;
	return (number_of_vertex);
}

int			ft_calculate_number_of_indices(t_mypolygon *polygon_node)
{
	int		number_of_indices;

	number_of_indices = 0;
	(void)polygon_node;
	return (number_of_indices);
}

int			*ft_calculate_indices_tab(t_mypolygon *polygon_node)
{
	int		*indices;

	indices = NULL;
	(void)polygon_node;
	return (indices);
}



void		ft_process_polygon(t_mypolygon *polygon_lst)
{
	t_mypolygon		*keep;
	int				i;

	keep = polygon_lst;
	i = 0;
	while (polygon_lst != NULL)
	{
		printf("polygone n=%d\n", i);
		printf("la normal :\n");
		polygon_lst->normal = ft_calculate_polygon_normal(polygon_lst);
		//polygon_lst->number_of_vertex = ft_calculate_number_of_vertex(polygon_lst);
		//polygon_lst->number_of_indices = ft_calculate_number_of_indices(polygon_lst);
		//polygon_lst->indices = ft_calculate_indices_tab(polygon_lst);
		polygon_lst = polygon_lst->next;
		i++;
	}
	polygon_lst = keep;
}

int			main(void)
{
	t_mywin		s_win;

	printf("hello chef Inca\n");
//	s_win.polygon_lst = ft_read_the_polygon_file();
//	ft_display_the_polygon_list(s_win.polygon_lst);
//	ft_process_polygon(s_win.polygon_lst);
	t_myvec v1, v2;
	float result;

	v1.x = 1;
	v1.y = 2;
	v1.z = 3;
	v2.x = 4;
	v2.y = 5;
	v2.z = 6;
	result = ft_dot_product(v1, v2);
	printf("the result =%f \n", result);
	return (1);
}
