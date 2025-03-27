/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:40:19 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/23 14:08:56 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"



int key_press(int keycode, t_game *game)
{
    t_keys *keys = &(game->data->keys); 
    // Update the movement states based on key press
	// printf("%d\n",game->data->keys.move_forward);
    if (keycode == KEY_W)
        keys->move_forward = 1;
    else if (keycode == KEY_S)
        keys->move_backward = 1;
    else if (keycode == KEY_A)
        keys->move_left = 1;
    else if (keycode == KEY_D)
        keys->move_right = 1;
    else if (keycode == KEY_LEFT)
        keys->turn_left = 1;
    else if (keycode == KEY_RIGHT)
        keys->turn_right = 1;
    else if (keycode == KEY_ESC)
    {
    	close_window(game->mlx);
    }
    return (0);
}

int key_release(int keycode, t_game *game)
{
    t_keys *keys = &(game->data->keys);
    // Update the movement states based on key release
    if (keycode == KEY_W)
        keys->move_forward = 0;
    else if (keycode == KEY_S)
        keys->move_backward = 0;
    else if (keycode == KEY_A)
        keys->move_left = 0;
    else if (keycode == KEY_D)
        keys->move_right = 0;
    else if (keycode == KEY_LEFT)
        keys->turn_left = 0;
    else if (keycode == KEY_RIGHT)
        keys->turn_right = 0;
    return (0);
}


void update_player_position(t_player *player, t_keys *keys, t_data *data)
{
    float move_step = player->move_speed;  // Movement speed
    float turn_step = player->turn_speed;  // Rotation speed

    // Rotate left/right (turn)
    if (keys->turn_left)
        player->playerA -= turn_step;  // Rotate counterclockwise
    if (keys->turn_right)
        player->playerA += turn_step;  // Rotate clockwise
    float moveX = 0.0f;
    float moveY = 0.0f;

    if (keys->move_forward) /// good
    {
        moveY += cosf(player->playerA) * move_step;
        moveX += sinf(player->playerA) * move_step;
    }
    if (keys->move_backward) /// good
    {
        moveY -= cosf(player->playerA) * move_step;
        moveX -= sinf(player->playerA) * move_step;
    }
    if (keys->move_left)
    {
        moveY += cosf(player->playerA - M_PI / 2) * move_step; // was other way arround
        moveX += sinf(player->playerA - M_PI / 2) * move_step;
    }
    if (keys->move_right)
    {
        moveY += cosf(player->playerA + M_PI / 2) * move_step; // was other way arround
        moveX += sinf(player->playerA + M_PI / 2) * move_step;
    }
	// wall check
    int nextX = (int)(player->playerX + moveX);
    int nextY = (int)(player->playerY + moveY);
    if (data->map_two_d[nextY][nextX] != '1')  // Only move if there's no wall
    {
        player->playerX += moveX;
        player->playerY += moveY;
    }
    //  printf("%c\n",data->map_two_d[nextY][nextX]);
    // else
    //     
}

int	close_window(t_mlx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->mlx_p, mlx->window);
	if (mlx->mlx_p)
	{
		mlx_destroy_display(mlx->mlx_p);
		free(mlx->mlx_p);
	}
	printf("GAME OVER!\n");
	free_map(mlx->data);
	free_data(mlx->data);
	//free_mlx(mlx->data);
	exit(0);
    //return(0);
}