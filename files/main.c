/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:46:46 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/07 19:55:07 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

int render_next_frame(t_alls *sts);

int	my_destroy(t_alls *sts)
{
    if (sts)
    {
        printf("self destruct sequence initiated: 3... 2... 1...\n");
       mlx_destroy_window(sts->wndw.mlx_image, sts->wndw.mlx_windows);
    }
    //return(0);
	exit(0);
}


int	my_keys(int keycode, t_alls *sts)
{
    if (sts)
    {
        if (keycode == 13)
            on_w(sts);
        else if (keycode == 0)
            on_a(sts);
        else if (keycode == 1)
            on_s(sts);
        else if (keycode == 2)
            on_d(sts);
        else if (keycode == 123)
            on_left(sts);
        else if (keycode == 124)
            on_right(sts);
        else if (keycode == 53)
            my_destroy(sts);
    }
    return(0);
	//exit(0);
}

int	my_keys_release(int keycode, t_alls *sts)
{
    if (sts)
    {
        printf("test\n");
        if (keycode == 13)
        {
            printf("w release\n");
            sts->keyrls = 13;
        }
        else if (keycode == 0)
            return (0);
        else if (keycode == 1)
            return (1);
        else if (keycode == 2)
            return (2);
        else if (keycode == 123)
            return (123);
        else if (keycode == 124)
            return (124);
    }
    return(999);
	//exit(0);
}

int main (int argc, char *argv[])
{
    t_alls *sts;
    int map_path_len;
    int parse;

    if (argc > 2)
        return (0);
    sts = (t_alls *)malloc(sizeof(t_alls));
    if (sts == NULL)
        return (0);
    map_path_len = ft_strlen(argv[1]);
    sts->paths.map_path = (char *)malloc(sizeof(char) * map_path_len);
    if (sts->paths.map_path == NULL)
        return (0);
    sts->paths.map_path = argv[1];
    sts->paths.map_path[map_path_len] = '\0';
    parse = start_parsing(sts);
    
    int i = 0;
    //printf("\nX resolution is: %d\n", sts->resolution.x);
    //printf("Y resolution is: %d\n\n", sts->resolution.y);
    printf("ceiling RGB color is: %d, %d, %d\n", sts->ceiling_color.r, sts->ceiling_color.g, sts->ceiling_color.b);
    printf("floor RGB color is: %d, %d, %d\n\n", sts->floor_color.r, sts->floor_color.g, sts->floor_color.b);
    printf("path to nord texture is: %s\n", sts->paths.n_path);
    printf("path to south texture is: %s\n", sts->paths.s_path);
    printf("path to east texture is: %s\n", sts->paths.e_path);
    printf("path to west texture is: %s\n", sts->paths.w_path);
    //printf("path to sprite texture is: %s\n\n", sts->paths.sprite_path);
    while(sts->map[i] != NULL)
    {
        printf("%s\n", sts->map[i]);
        i++;
    }
    printf("\n");





//img = image_data   
//cam = camera
    
    sts->wndw.mlx_image = mlx_init();
    sts->image_data = create_image(sts->resolution.x, sts->resolution.y, sts->wndw.mlx_image);
    sts->camera = create_cam(*create_vec2(14,4), *create_vec2(1,0), *create_vec2(0,0.66));
    sts->wndw.mlx_windows = mlx_new_window(sts->wndw.mlx_image, sts->resolution.x, sts->resolution.y, "TEST");
    sts->frame = 0;
    //mlx_loop_hook(mlx, render_next_frame, YourStruct);
	//mlx_loop(mlx);
    sts->keyrls = 999;
    sts->move.posX = 7.5;
    sts->move.posY = 1.5;  //x and y start position
    sts->move.dirX = 0;
    sts->move.dirY = 1; //initial direction vector
    sts->move.planeX = 1.2;
    sts->move.planeY = 0; //the 2d raycaster version of camera plane
    mlx_loop_hook(sts->wndw.mlx_image, render_next_frame, sts);
    mlx_hook(sts->wndw.mlx_windows, 2, 1L<<0, my_keys, sts);
    mlx_hook(sts->wndw.mlx_windows, 17, 0L, my_destroy, sts);
    mlx_hook(sts->wndw.mlx_windows, 3, 1L<<1, my_keys_release, sts);
    mlx_loop(sts->wndw.mlx_image);
   
    
    //while(sts->frame < 255)
    //{
        /*
        int x;
        double posX = 7.0, posY = 1.0;  //x and y start position
        //prendere informazione dalla struttura
        double dirX = 0, dirY = 1; //initial direction vector
        double planeX = 1.2, planeY = 0; //the 2d raycaster version of camera plane
        x = 0;

        while (x < sts->resolution.x)
        {
            //calcolo posizione e direzione del raggio 
            double cameraX = 2 * x / (double)sts->resolution.x - 1;

            double rayDirX = dirX + planeX * cameraX;
            double rayDirY = dirY + planeY * cameraX;

            //printf("x: %d raydirX: %f raydirY: %f dirX: %f dirY: %f\n", x, rayDirX, rayDirY, dirX, dirY);
            
            if((dirX <= (sqrtf(2) / 2) && dirY >= -(sqrtf(2) / 2)) && (dirX <= -(sqrtf(2) / 2)))
                rayDirY *= -1;
            if((dirX <= (sqrtf(2) / 2) && dirY >= -(sqrtf(2) / 2)) && (dirY >= (sqrtf(2) / 2)))
                rayDirX *= -1;

            ///printf("x: %d raydirX: %f raydirY: %f dirX: %f dirY: %f\n\n", x, rayDirX, rayDirY, dirX, dirY);
            //box della mappa in cui siamo 
            int mapX = (int)posX;
            int mapY = (int)posY;

            //lunghezza del raggio dalla poszione corrente alla prossima linea x o y
            double  sideDistX;
            double  sideDistY;

            //lunghezza del raggio da una lindea x o y alla prossima linea x o y
            double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
            double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
            double perpWallDist;
            

            int hit = 0; //hit controller
            int side; // NS-EW controller
            //printf("1\n");
            //step e sideDist iniziale
            int stepX = 0;
            int stepY = 0;
            if (rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (posX - (double)mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = ((double)mapX + 1.0 - posX) * deltaDistX;
            }
            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (posY - (double)mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = ((double)mapY + 1.0 - posY) * deltaDistY;
            }
            //printf("deltaX %f sidedistX %f sidedistY %f\n",deltaDistX, sideDistX, sideDistY);
            //DDA
           // printf("2\n");
            hit = 0;
            while (hit == 0)
            {
                //passa al prossimo quadrato di mappa, in direzione x o y
                if (sideDistX < sideDistY)
                {
                    sideDistX += deltaDistX;
                    mapX += stepX;
                    side = 0;
                }
                else
                {
                    sideDistY += deltaDistY;
                    mapY += stepY;
                    side = 1;
                }
                
                //controlla se il raggio ha colpito qualcosa
                if (sts->map[mapY][mapX] > 48) 
                    hit = 1;
                //printf("x %d y %d hit %d", hit);
            }
            ///printf("%d", side);
            //printf("%d\n", x);
           // printf("3\n");
            //printf ("raydiry %f stepX %d stepY %d mapX %d mapY %d deltaX %f deltaY %f sideX %f sideY %f\n",rayDirY, stepX, stepY, mapX, mapY, deltaDistX, deltaDistY, sideDistX, sideDistY);
            if (side == 0)
                perpWallDist = (sideDistX - deltaDistX);
            else
                perpWallDist = (sideDistY - deltaDistY);
            //printf("side %d walldist: %f sideX %f deltaX %f sideY %f deltaY %f\n", side, perpWallDist, sideDistX, deltaDistX, sideDistY, deltaDistY);
            //altezza della linea da disegnare
           // printf("4\n");
            int lineHeight = (int)((double)sts->resolution.y / perpWallDist);
            //calclo pixel piu' alto e pixel piu'basso della striscia corrente
            int drawStart = - lineHeight / 2 + sts->resolution.y / 2;
            if (drawStart < 0)
                drawStart = 0;
            if (drawStart >= sts->resolution.y)
                drawStart = sts->resolution.y - 1;
            
            int drawEnd = lineHeight / 2 +  sts->resolution.y / 2;
            if (drawEnd >= sts->resolution.y)
                drawEnd = sts->resolution.y - 1;
            if (drawEnd < 0)
                drawEnd = 0;
            //printf("x: %d cameraX %f rayDirx %f rayDirY %f sideDistX: %f sideDistY: %f distanza: %f\n", x, cameraX, rayDirX, rayDirY, sideDistX, sideDistY, perpWallDist);



            //printf("5\n");
           
           // mlx_key_hook(mlx_image, ));
           // printf("lh: %d, ds: %d, de:%d, h: %d",lineHeight, drawStart, drawEnd, sts->resolution.y);

            int wall_color = make_color(0, 255, 0, 0);
            int floor_color = make_color(0, 70, 70, 70);
            int roof_color = make_color(0, 0, j/255, 0);

            if (side == 1)
            {
                wall_color = wall_color / 2;
            }
           // printf("6\n");
            verticalStripe(sts->image_data, x, 0, drawStart, roof_color);
            verticalStripe(sts->image_data, x, drawStart, drawEnd, wall_color);
            verticalStripe(sts->image_data, x, drawEnd, 1079, floor_color);
            
            x++;
        }
        //printf("\n");
//        int color = make_color(0, 255, 0, 0);
//        for (int c = 200; c <= 600; c++)
//            verticalStripe(sts->image_data, c, 200, 600, color);

    create_image_windows(mlx_windows, sts->image_data, mlx); 
    
    }*/
    
   // printf("frame: %d\n", sts->frame);
    //sts->frame++;
   // }
}
   

