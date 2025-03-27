/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:36:59 by msacaliu          #+#    #+#             */
/*   Updated: 2024/09/23 13:27:44 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


void put_pixel_to_image(char *img_data, int x, int y, int color, int size_line, int bits_per_pixel)
{
    int pixel_position;
	
    // Calculate the memory position of the pixel in the buffer
    pixel_position = (y * size_line) + (x * (bits_per_pixel / 8));

    // Check bounds to avoid writing outside the image data
    if (pixel_position < 0 || pixel_position >= size_line * S_H - (bits_per_pixel / 8))
    {
        return ;
    }
	
    // Update the pixel color in the image buffer (assuming 32 bits per pixel)
    img_data[pixel_position] = color & 0xFF;            // Blue
    img_data[pixel_position + 1] = (color >> 8) & 0xFF; // Green
    img_data[pixel_position + 2] = (color >> 16) & 0xFF; // Red
    if (bits_per_pixel == 32)
	{
        img_data[pixel_position + 3] = (color >> 24) & 0xFF; // Alpha channel (optional)
	}
}


// ----test----
void render_column(int x, int ceiling, int floor, t_data *data)
{
	int y;
    // Draw ceiling
    for (y = 0; y < ceiling; y++)
    {
        put_pixel_to_image(data->img_data, x, y, 0x00FF00, data->size_line, data->bits_per_pixel); // Green
    }
    // Draw wall
    for (y = ceiling; y <= floor; y++)
    {
        int tex_x = (x % data->img_width); 
        int tex_y = (y - ceiling) * data->img_height / (floor - ceiling);
        // *** CHANGED *** char *pixel_addr = data->wall_data + (tex_y * data->size_line + tex_x * (data->bits_per_pixel / 8));
        char *pixel_addr = data->wall_data + (tex_y * data->img_width * (data->bits_per_pixel / 8)) + (tex_x * (data->bits_per_pixel / 8));
        int color = *(int *)pixel_addr;
        put_pixel_to_image(data->img_data, x, y, color, data->size_line, data->bits_per_pixel);
    }
    // Draw floor
    for (y = floor; y < S_H; y++)
	{
        put_pixel_to_image(data->img_data, x, y, 0x888888, data->size_line, data->bits_per_pixel); // Gray
    }
}

void render_textures(t_mlx *mlx, int x, float distance_to_wall, t_data *data) {
    int ceiling;
    int floor;
    // int y = 0;
	(void)mlx;

    ceiling = (float)(S_H / 2.0) - S_H / (float)distance_to_wall;
    if (ceiling < 0)
		ceiling = 0;
    floor = S_H - ceiling;
    if (floor > S_H)
		floor = S_H;

    render_column(x, ceiling, floor, data);
}

float	cast_rays(int x, t_player *player, t_data *data)
{
	float	ray_angle;
	float	distance_to_wall;
	bool	hit_wall;
	// for each column calculate the projected ray angle in to world space
	ray_angle = (player->playerA - player->FOV / 2.0f) + ((float)x / (float)S_W ) * player->FOV;
	float	eyeX = sinf(ray_angle);
	float	eyeY = cosf(ray_angle);
	distance_to_wall = 0;
	hit_wall = false;
	while(!hit_wall && distance_to_wall < player->depth)
	{
		distance_to_wall += 0.1f;
		player->testX = (int)(player->playerX + eyeX * distance_to_wall);
		player->testY = (int)(player->playerY + eyeY * distance_to_wall);
		// check for ray out of bounds;
        // printf("Map dimensionsdfsfgdfgdfgdfgs: %d x %d\n", data->width, data->height);
		if (player->testX < 0 || player->testX >= data->width || player->testY < 0 || player->testY >=data->height)
		{
			hit_wall = true;
			distance_to_wall = player->depth;
		}

		else if (data->map_two_d[player->testY][player->testX] == '1')
			hit_wall = true;
	}
	return (distance_to_wall);
}


void load_textures(t_data *data, t_mlx *mlx) {


    // // Load the wall texture
    data->wall_img = mlx_xpm_file_to_image(mlx->mlx_p, "./textures/wall.xpm", &data->img_width, &data->img_height);
    if (!data->wall_img)
	{
        printf("Failed to load wall texture\n");
        exit(1);
    }
    // Get the image data address
    data->wall_data = mlx_get_data_addr(data->wall_img, &data->bits_per_pixel, &data->size_line, &data->endian);
    if (!data->wall_data)
	{
        printf("Failed to get wall texture data address\n");
        exit(1);
    }
}

int redraw_image(t_game *game)
{
    int x = 0;
    float distance_to_wall = 0;
		
	game->data->img = mlx_new_image(game->mlx->mlx_p, S_W, S_H);
	game->data->img_data = mlx_get_data_addr(game->data->img, &game->data->bits_per_pixel, &game->data->size_line, &game->data->endian);
    while (x < S_W) // raycast every column
    {
		
        distance_to_wall = cast_rays(x, game->player , game->data);
        render_textures(game->mlx, x, distance_to_wall, game->data);
        x++;
    }
	    mlx_put_image_to_window(game->mlx->mlx_p, game->mlx->window, game->data->img, 0, 0);
		mlx_destroy_image(game->mlx->mlx_p, game->data->img);
    return (0);
}


// ---------------org one----------


// void	render_textures(t_mlx *mlx, int x, float distance_to_wall, t_data *data, int size_line, int bits_per_pixel)
// {
// 	int ceiling;
// 	int floor;
// 	int y;
// 	y = 0;
// 	(void)mlx;
// 	void *wall_img = mlx_xpm_file_to_image(mlx->mlx_p, "./textures/wall.xpm", &data->img_width, &data->img_height);
// 	if(!wall_img)
// 	{
// 		printf( "!!!!!111Failed to load wall texture\n"); // jus t for debugging
//         return;
// 	}
//     // Get the image data
//     data->wall_data = mlx_get_data_addr(wall_img, &data->bits_per_pixel, &data->size_line, &data->endian);
// 	if (!data->wall_data)
//     {
//         printf( "Failed to load wall texture\n"); // jus t for debugging
//         return;
//     }
// 	ceiling = (float)(S_H / 2.0) - S_H / (float)distance_to_wall;
// 	if (ceiling < 0)
// 		ceiling = 0;
// 	floor = S_H - ceiling;
// 	if (floor > S_H)
// 		floor = S_H; 
// 	while(y < S_H)
// 	{
// 		if (y < ceiling)
// 		{
// 			put_pixel_to_image(data->img_data, x, y, 0x00FF00,size_line,bits_per_pixel);
// 			// mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, 0x00FF00); // Ceiling (green)
// 		}
			
// 		else if (y >= ceiling && y <= floor) // if between ceiling and floor draw wall
// 		{
// 			// int tex_y = (y - ceiling) * data->img_height / (floor - ceiling);
// 			// int color = *(int *)(data->wall_data + (tex_y * data->size_line + (x % data->img_width) * (data->bits_per_pixel / 8)));
// 			// // color =	*(int *)(img_data + (y * data->size_line + x * (data->bits_per_pixel / 8)));
// 			int tex_y = (y - ceiling) * data->img_height / (floor - ceiling); // Map the y-position to the texture height
//             int tex_x = (x % data->img_width); // Map the x-position to the texture width
//             int color = *(int *)(data->wall_data + (tex_y * data->size_line + tex_x * (data->bits_per_pixel / 8)));
// 			put_pixel_to_image(data->img_data, x, y, color,size_line,bits_per_pixel);

// 			// mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, color); // Wall texture
// 		}
// 		else
// 			put_pixel_to_image(data->img_data, x, y, 0x888888,size_line,bits_per_pixel);

// 			// mlx_pixel_put(mlx->mlx_p, mlx->window, x, y, 0x888888); // Floor (gray)
			
// 		y++;
// 	}
	
// }



// void load_textures(t_data *data, t_mlx *mlx) {
//     data->wall_img = mlx_xpm_file_to_image(mlx->mlx_p, "./textures/wall.xpm", &data->img_width, &data->img_height);
//     if (!data->wall_img) {
//         printf("Failed to load wall texture\n");
//         exit(1);
//     }
//     data->wall_data = mlx_get_data_addr(data->wall_img, &data->bits_per_pixel, &data->size_line, &data->endian);
// }






    // for (y = ceiling; y <= floor; y++) {
    //     int tex_y = (y - ceiling) * data->img_height / (floor - ceiling); // Map the y-position to the texture height
    //     int tex_x = (x % data->img_width); // Map the x-position to the texture width

    //     // Check bounds for texture coordinates
    //     if (tex_y < 0 || tex_y >= data->img_height || tex_x < 0 || tex_x >= data->img_width) {
    //         printf("Texture coordinates out of bounds: tex_x=%d, tex_y=%d\n", tex_x, tex_y);
    //         continue;
    //     }

    //     int color = *(int *)(data->wall_data + (tex_y * data->size_line + tex_x * (data->bits_per_pixel / 8)));
    //     put_pixel_to_image(data->img_data, x, y, color, data->size_line, data->bits_per_pixel);
    // }