/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:42:06 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/23 14:15:03 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


int  get_player_x_position(t_data *data, t_player *player)
{
    int y = 0;
	int x = 0;
	(void)player;
	// int flag_player = 0;
    while (data->map_two_d[y] != NULL)
    {
        x = 0;
        while (data->map_two_d[y][x] != '\0')
        {
            if (data->map_two_d[y][x]== 'N')
            {
				return(x);
                // flag_player = 1;  
            }
				
            x++;
        }
        y++;
    }
	return(3);
}
int  get_player_y_position(t_data *data, t_player *player)
{
    int y = 0;
	(void)player;

	int x = 0;
    while (data->map_two_d[y] != NULL)
    {
        x = 0;
        while (data->map_two_d[y][x] != '\0')
		{          
			  printf("Checking position y=%d, x=%d, value=%c\n", y, x, data->map_two_d[y][x]);

            if (data->map_two_d[y][x] == 'N')
            {
				printf("test\n");
                return(y);
                // flag_player = 1;  
            }
				
            x++;
        }
        y++;
    }
	return(4);
}

t_player *init_player(t_data *data) /// need to free the alloc
{
	t_player *player;
	
	player = (t_player *)malloc(sizeof(t_player)); // Allocate memory for the player

    if (player == NULL)
    {
        return NULL;
    }
	// (void)data;
	player->playerX = (float)get_player_x_position(data, player);
	player->playerY = (float)get_player_y_position(data,player);
	// player->playerX = 1.0f;
	// player->playerY = 14.0f;

	// player->playerY = 5.0f;
	printf(" ---x: %f\n", player->playerX);
	printf(" ---y: %f\n", player->playerY);
	player->playerA = 0.0f;
	player->FOV = 3.14159 / 2.5; // 60
	player->depth = 24.0;  // Maximum depth of the map (distance of ray)
	player->move_speed = 0.2f;
	player->turn_speed = 0.05f;
	return(player);
}

void init_keys(t_keys *keys)
{
    keys->move_forward = 0;
    keys->move_backward = 0;
    keys->move_left = 0;
    keys->move_right = 0;
    keys->turn_left = 0;
    keys->turn_right = 0;
}