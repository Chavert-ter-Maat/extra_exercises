/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_count.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 15:20:45 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/11/06 16:14:13 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_node 
{
	struct	s_node *left;
	struct	s_node *right;
}	t_node;

t_node	*new_node(void) 
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int total_nodes(t_node *node)
{
    if (node == NULL)
        return 0;
    int lDepth = total_nodes(node->left);
    int rDepth = total_nodes(node->right);
    return (lDepth + rDepth + 1);
}

int main(void)
{
	t_node *head;
	head = new_node();
	head->left = new_node();
	head->right = new_node();
    printf("%i", total_nodes(head));
    return (0);
}

