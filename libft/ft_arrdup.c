/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:50:39 by svan-hoo          #+#    #+#             */
/*   Updated: 2024/06/27 20:52:37 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Duplicate a NULL-terminated array of pointers
char	**ft_arrdup(char **arr)
{
	char	**dup;
	int		i;

	i = 0;
	while (arr[i])
		++i;
	dup = (char **)malloc((i + 1) * sizeof(char *));
	if (dup == NULL)
		return (NULL);
	dup[i] = NULL;
	while (i--)
	{
		dup[i] = ft_strdup(arr[i]);
		if (!dup[i])
			return (ft_free_ptr_array(dup), NULL);
	}
	return (dup);
}
