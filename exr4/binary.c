/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   binary.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 13:40:51 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/11/08 09:50:55 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_node {
	int		value;
	struct	s_node* left;
	struct	s_node* right;
}				t_node;

t_node	*newNode(int value) 
{
	t_node* node;

	node = malloc(sizeof(t_node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
}

int		SearchValue(t_node *node, int value)
{
	if (node == NULL)
		return (0);
	else
	{
		if (node->value == value)
			return (1);
			int lDepth = SearchValue(node->left, value);
			int rDepth = SearchValue(node->right, value);
			if (lDepth || rDepth)
				return (1);
			return (0);
	}
}

int main()
{
	t_node* root;

	root = newNode(1);
}