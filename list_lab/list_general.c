/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:57:05 by svan-hoo          #+#    #+#             */
/*   Updated: 2024/06/26 22:12:49 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_types.h"

void	*
	lstlast(
		void **head,
		t_getnext_func getnext)
{
	void	*temp;

	if (head == NULL)
		return (NULL);
	temp = *head;
	while (getnext(temp) != NULL)
		temp = getnext(temp);
	return (temp);
}

void
	lstadd_back(
		void **head,
		t_getnext_func getnext,
		void *new_node)
{
	if (!head || !new_node)
		return ;
	lstlast(head, getnext) = new_node;
}
