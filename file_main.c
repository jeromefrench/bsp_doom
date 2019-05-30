/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:34:03 by jchardin          #+#    #+#             */
/*   Updated: 2019/05/30 11:12:23 by jchardin         ###   ########.fr       */
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

t_myvec		ft_vector_from_two_points(t_myvec v2, t_myvec v1)
{
	t_myvec			result;

	result.x = v2.x - v1.x;
	result.y = v2.y - v1.y;
	result.z = v2.z - v1.z;
	return (result);
}

int			ft_classify_point(t_myvec point, t_mypolygon *plane)
{
	float		result;
	t_myvec		direction;

	direction = ft_vector_from_two_points(*plane->vertex_lst, point);//pas sur de l'etoile
	result = ft_dot_product(direction, plane->normal);
	if (result < - 0.001)
		return (FRONT);
	else if (result > 0.001)
		return (BACK);
	else
		return (ON_PLANE);
}

int			ft_classify_polygon(t_mypolygon *plane, t_mypolygon *polygon_node)
{
	int			front;
	int			back;
	int			on_plane;
	int			result;
	t_myvec		*keep;

	result = 0;
	front = 0;
	back = 0;
	on_plane = 0;
	keep = mypolygon_node->vertex_lst;
	while (t_mypolygon->vertex_lst != NULL)
	{
		result = ft_classify_point(polygon_node->vertex_lst, plane);
		if (result == FRONT)
			front++;
		else if (result == BACK)
			back++;
		else
		{
			on_plane++;
			front++;
			back++;
		}
		polygon_node->vertex_lst = polygon_node->vertex_lst->next;
	}
	t_mypolygon->vertex_lst = keep;









}

int			main(void)
{
	t_mywin		s_win;

	printf("hello chef Inca\n");
	s_win.polygon_lst = ft_read_the_polygon_file();
	ft_display_the_polygon_list(s_win.polygon_lst);
	ft_process_polygon(s_win.polygon_lst);
	return (1);
}
