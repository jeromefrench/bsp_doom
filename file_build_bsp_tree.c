/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_build_bsp_tree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 18:02:54 by jchardin          #+#    #+#             */
/*   Updated: 2019/06/01 18:03:40 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bsp.h"

void		ft_build_bsp_tree(t_mynode *current_node, t_mypolygon *polygon_lst)
{
	t_mypolygon		*poly_test = NULL;
	t_mypolygon		*front_list = NULL;
	t_mypolygon		*back_list = NULL;
	t_mypolygon		*next_poly = NULL;
	t_mypolygon		*front_split = NULL;
	t_mypolygon		*back_split = NULL;
	t_myvec			vec1;
	t_myvec			vec2;
	int				result_classify;

	current_node->splitter = ft_select_the_best_poly_splitter(polygon_lst);
	poly_test = polygon_lst;

	while (poly_test != NULL)
	{
		next_polygon = poly_test->next; //we do it now cuz the next will be altered further
		if (polygtest != current_node->splitter)
		{
			result_classify = ft_classify_polygon(current_node->splitter, poly_test);
			if (result_classify == FRONT)
			{
				polytest->next = front_list;
				front_list = poly_test;
			}
			else if (result_classify == BACK)
			{
				polytest->next = back_list;
				back_list = poly_test;
			}
			else if (result_classify == SPANNING)
			{
				t_mypolygon		*new_polygon_front;
				t_mypolygon		*new_polygon_back;


				front_split = new_polygon_front;
				back_split = new_polygon_back;


				//zero memory (front_split, sizeof(polygon))
				//zero memory (back_split, sizeof(polygon))

				ft_split_polygon(poly_test, current_node->splitter, front_split, back_split);

				//delete poly_test
				front_split->next = front_list;
				front_list = front_split;
				back_split->next = backList;
				back_list = back_split;
			}
			else
				printf("error\n");
		}
		poly_test = next_polygon;
	}
	//////////////////////////////////////

	if (front_list == NULL)
	{
		t_mynode	*new_node;
		//zero memory (new_node node, ...)
		leaf_node->is_leaf = TRUE;
		leaf_node->is_solid = FALSE;
		current_node->front = leaf_node;
	}
	else
	{
		t_mynode	*new_node;
		//zero memory (new_node, ...)
		new_node->is_leaf = FALSE;
		current_node->front = new_node;
		ft_build_bsp_tree((new_node), front_list);  //////->recursivity
	}
	////////////////////////////

	if (BackList == NULL)
	{
		NODE *leaf_node = new NODE;
		//ZeroMemory(leaf_node,sizeof(leaf_node));
		leaf_node->Is_Leaf=TRUE;
		leaf_node->Is_Solid=TRUE;
		Current_Node->Back=leaf_node;;
	}
	else
	{
		NODE *new_node = new NODE;
		//ZeroMemory(new_node,sizeof(new_node));
		new_node-> is_leaf = FALSE;
		current_node->back = new_node;
		ft_build_bsp_tree(new_node, back_List);    //////->recursivity
	}
}
