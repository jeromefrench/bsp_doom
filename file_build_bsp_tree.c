/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_build_bsp_tree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 18:02:54 by jchardin          #+#    #+#             */
/*   Updated: 2019/06/02 14:05:24 by jchardin         ###   ########.fr       */
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

	printf("\n\t===>Construction d'un noeud<===\n");
	printf("Pour ce noeud notre splitter contient %d vertex\n", current_node->splitter->number_of_vertex);
	while (poly_test != NULL)
	{
		next_poly = poly_test->next; //we do it now cuz the next will be altered further
		if (poly_test != current_node->splitter)
		{
			printf("on va classer le poly contenant %d vertex ", poly_test->number_of_vertex);

			result_classify = ft_classify_polygon(current_node->splitter, poly_test);
			if (result_classify == FRONT)
			{
				printf("Il est devant le spliter\n");
				poly_test->next = front_list;
				front_list = poly_test;
			}
			else if (result_classify == BACK)
			{
				printf("Il est derriere le spliter\n");
				poly_test->next = back_list;
				back_list = poly_test;
			}
			else if (result_classify == SPANNING)
			{
				printf("Il est spanning le spliter\n");
				t_mypolygon		*new_polygon_front;
				t_mypolygon		*new_polygon_back;

				front_split = new_polygon_front;
				back_split = new_polygon_back;
				//zero memory (front_split, sizeof(polygon))
				//zero memory (back_split, sizeof(polygon))
				//ft_split_polygon(poly_test, current_node->splitter, front_split, back_split);
				printf("ft_split a regarder non teste pour le moment\n");
				//delete poly_test
				front_split->next = front_list;
				front_list = front_split;
				back_split->next = back_list;
				back_list = back_split;
			}
			else
				printf("error\n");
		}
		poly_test = next_poly;
	}

	//////////////////////////////////////
	if (front_list == NULL)
	{
		t_mynode		*leaf_node;
		//zero memory (new_node node, ...)
		leaf_node->is_leaf = TRUE;
		leaf_node->is_solid = FALSE;
		current_node->front = leaf_node;
	}
	else
	{
		t_mynode		*new_node;
		//zero memory (new_node, ...)
		new_node->is_leaf = FALSE;
		current_node->front = new_node;
		ft_build_bsp_tree((new_node), front_list);  //////->recursivity
	}
	////////////////////////////
	if (back_list == NULL)
	{
		t_mynode		*leaf_node;
		//ZeroMemory(leaf_node,sizeof(leaf_node));
		leaf_node->is_leaf = TRUE;
		leaf_node->is_solid = TRUE;
		current_node->back = leaf_node;;
	}
	else
	{
		t_mynode		*new_node;
		//ZeroMemory(new_node,sizeof(new_node));
		new_node-> is_leaf = FALSE;
		current_node->back = new_node;
		ft_build_bsp_tree(new_node, back_list);    //////->recursivity
 	}
}
