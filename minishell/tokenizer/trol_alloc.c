/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trol_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:52:15 by albealva          #+#    #+#             */
/*   Updated: 2024/12/08 19:48:49 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*my_realloc_char(char *ptr, size_t new_size)
{
	size_t	old_size;
	size_t	i;
	char	*new_ptr;
	size_t	size_to_copy;

	old_size = get_old_size(ptr);
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return ((char *)malloc(new_size));
	new_ptr = (char *)malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	i = -1;
	if (old_size < new_size)
		size_to_copy = old_size;
	else
		size_to_copy = new_size;
	while (i++ < size_to_copy)
		new_ptr[i] = ptr[i];
	free(ptr);
	return (new_ptr);
}

void	*my_malloc(t_general *info, size_t size)
{
	t_memorymanager	*manager;
	void			*ptr;

	manager = &info->manager;
	if (manager == NULL)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		free_all_allocated_blocks(info);
	if (ptr != NULL)
	{
		manager->total_allocated += size;
		manager->allocated_blocks[manager->block_count].ptr = ptr;
		manager->allocated_blocks[manager->block_count].size = size;
		manager->block_count++;
		manager->total_allocs++;
	}
	return (ptr);
}

void	my_free(t_general *info, void *ptr)
{
	t_memorymanager	*manager;
	int				i;

	i = 0;
	manager = &info->manager;
	if (manager == NULL)
		return ;
	while (i < manager->block_count)
	{
		if (manager->allocated_blocks[i].ptr == ptr)
		{
			manager->total_allocated -= manager->allocated_blocks[i].size;
			free(ptr);
			manager->allocated_blocks[i] = manager->allocated_blocks
			[--manager->block_count];
			return ;
		}
		i++;
	}
}

void	free_all_allocated_blocks(t_general *info)
{
	t_memorymanager	*manager;
	int				i;

	i = 0;
	manager = &info->manager;
	if (manager == NULL)
		return ;
	while (i < manager->block_count)
	{
		free(manager->allocated_blocks[i].ptr);
		i++;
	}
	manager->block_count = 0;
	manager->total_allocated = 0;
}
