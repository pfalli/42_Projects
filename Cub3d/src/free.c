/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:53:27 by pfalli            #+#    #+#             */
/*   Updated: 2024/09/19 10:53:49 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/cub3d.h"

void free_map(t_data *data)
{
    if (data == NULL || data->map_two_d == NULL)
        return;
    int i = 0;
    while (data->map_two_d[i] != NULL)
    {
        //printf("Freeing map_two_d[%d]\n", i);
        free(data->map_two_d[i]);
        i++;
    }
    //printf("END Freeing map_two_d\n\n");
    free(data->map_two_d);
}

// void free_mlx(t_data *data)
// {
//     if (data->mlx != NULL)
//     {
//         mlx_destroy_display(data->mlx);
//         free(data->mlx);
//     }
// }

void free_data(t_data *data)
{
    if (data == NULL)
        return;
    if (data->no_path != NULL)
    {
        //printf("Freeing no_path\n");
        free(data->no_path);
    }
    if (data->so_path != NULL)
    {
        //printf("Freeing so_path\n");
        free(data->so_path);
    }
    if (data->we_path != NULL)
    {
        //printf("Freeing we_path\n");
        free(data->we_path);
    }
    if (data->ea_path != NULL)
    {
        //printf("Freeing ea_path\n");
        free(data->ea_path);
    }
    if (data->map_path != NULL)
    {
        //printf("Freeing map_path\n");
        free(data->map_path);
    }
    //printf("END freeing data\n");
}