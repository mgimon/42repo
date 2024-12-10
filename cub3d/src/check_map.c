/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:10:59 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/10 22:04:29 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int get_full_width(char **matrix)
{
    int i;
    int j;
    int full_width;

    i = 0;
    full_width = 0;
    while (matrix[i])
    {
        j = 0;
        while (matrix[i][j])
            j++;
        if (j > full_width)
            full_width = j;
        i++;
    }
    return (full_width);
}

int get_full_height(char **matrix)
{
    int i;

    i = 0;
    while (matrix[i])
        i++;
    return (i);
}

int check_line_ends(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (1);
    while (str[i] == ' ')
        i++;
    if (str[i] != '1')
        return (1);
    i = ft_strlen(str) - 1;
    while (i >= 0 && str[i] == ' ')
        i--;
    if (str[i] != '1')
        return (1);
    return (0);
}

int is_it_closed(char **matrix, int full_width, int full_height)
{
    int i;
    int j;

    (void)full_width;
    i = 0;
    while (matrix[i])
    {
        if (check_line_ends(matrix[i]) != 0)
            return (1);
        j = 0;
        while (matrix[i][j])
        {
            if (i == 0 || i == (full_height - 1))
            {
                if (matrix[i][j] != '1' && matrix[i][j] != ' ')
                    return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int check_map(char **matrix)
{
    int full_width;
    int full_height;
    int closed;
    /*int slid_past;
    int player_valid;*/

    if (!matrix || !matrix[0])
        return (1);
    full_width = get_full_width(matrix);
    full_height = get_full_height(matrix);
    closed = is_it_closed(matrix, full_width, full_height);
    /*slid_past = has_it_slid(matrix, full_width, full_height);
    player_valid = does_player_exist(matrix); // also not more than one
    player_valid = is_player_free(matrix);
    if (closed == 0 && slid_past == 0 && player_valid == 0)
        return (0);*/
    if (closed == 0)
        return (0);
    return (1);
}