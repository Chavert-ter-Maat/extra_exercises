/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_search.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 14:55:25 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/11/06 16:12:23 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
} t_node;

t_node	*new_node(int value) 
{
	t_node* node;

	node = malloc(sizeof(t_node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

int search_value(t_node *node, int value)
{
    if (node == NULL)
        return (0);
    if (node->value == value || search_value(node->left, value) || search_value(node->right, value))
        return (1);
    return (0);
}

int main(void)
{
	t_node *head;
	head = new_node(10);
	head->left = new_node(3);
	head->right = new_node(1);
    if (search_value(head, 3))
        printf("found");
    else
        printf("not found");
    return(0);
}
