/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:10:03 by pfalli            #+#    #+#             */
/*   Updated: 2024/09/13 13:10:03 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// int	close_window(t_data *data)
// {
// 	mlx_destroy_window(data->mlx, data->win);
// 	printf("EXIT\n");
// 	free_map(data);
// 	free_data(data);
// 	free_mlx(data);
// 	exit(0);
// }

void draw_player(t_mlx *mlx, t_player *player, int cell_size)
{
	int player_size = cell_size / 2;
    int player_x = (int)(player->playerX * (cell_size));
    int player_y = (int)(player->playerY * (cell_size));
    int i = 0;
    while (i < player_size)
    {
        int j = 0;
        while (j < player_size)
        {
            mlx_pixel_put(mlx->mlx_p, mlx->window, player_x + i, player_y + j, 0xFF0000); // Red for player
            j++;
        }
        i++;
    }
}

void mini_map(t_data *data, t_mlx *mlx, t_player *player)
{
    int cell_size = 10;
    int x = 0, y = 0;

    while (data->map_two_d[y] != NULL)
    {
        x = 0;
        while (data->map_two_d[y][x] != '\0')
        {
            int color;
            if (data->map_two_d[y][x] == '1')
                color = 0xFFFFFF; // White for walls
            else if (data->map_two_d[y][x] == '0')
                color = 0x000000; // Black for empty space
            //  else
            //  {
            //      printf("Skipping invalid character '%c' at (%d, %d)\n", data->map_two_d[y][x], x, y);
            //      x++;
            //      continue;
            //  }
            //printf("Debug mini_map: cell (%d, %d) with value '%c' and color 0x%X\n", x, y, data->map_two_d[y][x], color);
            int i = 0;
            while (i < cell_size)
            {
                int j = 0;
                while (j < cell_size)
                {
                    mlx_pixel_put(mlx->mlx_p, mlx->window, x * cell_size + i, y * cell_size + j, color);
                    j++;
                }
                i++;
            }
            x++;
        }
        y++;
    }
	draw_player(mlx, player, cell_size);
}

void calculate_map_dimensions(t_data *data)
{
    int height = 0;
    int width = 0;
    int current_width;

    while (data->map_two_d[height] != NULL)
    {
        current_width = ft_strlen(data->map_two_d[height]);
        if (current_width > width)
        {
            width = current_width;
        }
        height++;
    }
    data->height = height;
    data->width = width;
}


//	int main(int argc, char **argv)
//	{
//	    t_data data;
//	
//	    if (argc != 2)
//	        return printf("Error, insert: ./cub3d <map_path> (ex: ./cub3d maps/valid.ber)\n"), 0;
//	    data.mlx = mlx_init();
//	    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D");
//	
//	    data.map_path = ft_strdup(argv[1]);
//	    parsing_map(&data);
//	
//	    mini_map(&data);
//	
//	    //mlx_loop_hook(data.mlx, loop, &data);
//	    mlx_hook(data.win, 17, 1L << 17, close_window, &data);
//	    mlx_loop(data.mlx);
//	
//	    return (0);
//	}