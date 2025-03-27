/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:52:37 by pfalli            #+#    #+#             */
/*   Updated: 2024/09/19 14:26:40 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


void invalid_char(t_data *data)
{
    int y = 0;
    while (data->map_two_d[y] != NULL)
    {
        int x = 0;
        while (data->map_two_d[y][x] != '\0')
        {
            char current_char = data->map_two_d[y][x];

            if (current_char != 'N' && current_char != '1' &&
                current_char != '0' && current_char != ' ' &&
                current_char != '\n' && current_char != '\r')
            {
                printf("Invalid or hidden char in map at (%d, %d): %c (ASCII: %d)\n", y, x, current_char, current_char);
                exit(EXIT_FAILURE);
            }
            x++;
        }
        y++;
    }
}
// check_colors is inside parse_color
void no_player(t_data *data)
{
    int y = 0;
	int flag_player = 0;
    while (data->map_two_d[y] != NULL)
    {
        int x = 0;
        while (data->map_two_d[y][x] != '\0')
        {
            if (data->map_two_d[y][x]== 'N')
            {
                // data->player->playerX = (float)x;
                // data->player->playerY =(float) y;
                flag_player = 1;  
            }
				
            x++;
        }
        y++;
    }
	if (flag_player == 0)
	{
		printf("Player not found inside map\n");
        exit(EXIT_FAILURE);
	}
}


void check_errors(t_data *data)
{
	invalid_char(data);
	no_player(data);
}