/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 09:51:25 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/31 11:12:30 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

static int	ascending(int a, int b)
{
	return (a <= b);
}

static void	add_back(t_list **lst, int data)
{
	t_list	*new;

	if (*lst == NULL)
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return ;
		new->data = data;
		new->next = *lst;
		*lst = new;
		return ;
	}
	new = *lst;
	while (new->next != NULL)
		new = new->next;
	new->next = malloc(sizeof(t_list));
	if (!new->next)
		return ;
	new->next->data = data;
	new->next->next = NULL;
}

static void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%i\n", lst->data);
		lst = lst->next;
	}
}


static void	swap_with_next(t_list *lst)
{
	int	tmp;

	tmp = (lst)->data;
	(lst)->data = (lst)->next->data;
	(lst)->next->data = tmp;
}

static int	sorted(t_list *lst, int (*cmp)(int, int))
{
	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*head;

	head = lst;
	while (sorted(lst, cmp) != 0)
	{
		while (lst->next)
		{
			if (cmp(lst->data, lst->next->data) == 0)
				swap_with_next(lst);
			lst = lst->next;
		}
		lst = head;
	}
	return (lst);
}


int	main(void)
{
	t_list	*lst;

	lst = NULL;
	add_back(&lst, 4);
	add_back(&lst, 3);
	add_back(&lst, -10);
	add_back(&lst, 3);
	printf("before sorting:\n");
	print_list(lst);
	sort_list(lst, ascending);
	printf("\nafter sorting:\n");
	print_list(lst);
	return (0);
}