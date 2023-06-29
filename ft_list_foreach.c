/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_foreach.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 14:18:19 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/30 14:19:30 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
#define FT_LIST_H

typedef struct    s_list
{
    struct	s_list *next;
    void	*data;
} t_list;

#endif

#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *)) 
{
    t_list *current = begin_list;
    while (current != NULL) 
	{
        (*f)(current->data);
        current = current->next;
    }
}