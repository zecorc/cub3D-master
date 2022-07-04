/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:46:46 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/04 18:39:30 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

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


    void        *mlx;
    
    mlx = mlx_init();
    sts->image_data = create_image(sts->resolution.x, sts->resolution.y, mlx);
    sts->camera = create_cam(*create_vec2(14,4), *create_vec2(1,0), *create_vec2(0,0.66));

   // while(1)
   // {
        int x;
        double posX = 10.5, posY = 10.5;  //x and y start position
        /* prendere informazione dalla struttura */double dirX = 1, dirY = 0; //initial direction vector
        double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
        x = 0;

        while (x < sts->resolution.x)
        {
            //calcolo posizione e direzione del raggio 
            double cameraX = 2 * x / (double)sts->resolution.x - 1;
            double rayDirX = dirX + planeX * cameraX;
            double rayDirY = dirY + planeY * cameraX;

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
            //printf("rayx %f rayY %f deltadistX = %f deltadistY %f\n",rayDirX, rayDirY, deltaDistX, deltaDistY);

            int hit = 0; //hit controller
            int side; // NS-EW controller
            printf("1\n");
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
            printf("2\n");
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
            printf("%d\n", x);
            printf("3\n");
            //printf ("raydiry %f stepX %d stepY %d mapX %d mapY %d deltaX %f deltaY %f sideX %f sideY %f\n",rayDirY, stepX, stepY, mapX, mapY, deltaDistX, deltaDistY, sideDistX, sideDistY);
            if (side == 0)
                perpWallDist = (sideDistX - deltaDistX);
            else
                perpWallDist = (sideDistY - deltaDistY);
            //printf("side %d walldist: %f sideX %f deltaX %f sideY %f deltaY %f\n", side, perpWallDist, sideDistX, deltaDistX, sideDistY, deltaDistY);
            //altezza della linea da disegnare
            printf("4\n");
            int lineHeight = (int)((double)sts->resolution.y / perpWallDist);
            //calclo pixel piu' alto e pixel piu'basso della striscia corrente
            int drawStart = - lineHeight / 2 + sts->resolution.y / 2;
            if (drawStart < 0)
                drawStart = 0;
            
            int drawEnd = lineHeight / 2 +  sts->resolution.y / 2;
            if (drawEnd >= sts->resolution.y)
                drawEnd = sts->resolution.y - 1;


/*
            printf("5\n");
            int color;
            switch(sts->map[mapY][mapX])
            {
                case 0:  color = make_color(0, 0, 200, 0);    break;
                case 1:  color = make_color(0, 145, 200, 255);    break;
                default: color = make_color(0, 255, 0, 0); break; //yellow
            }
        */    

            
           // mlx_key_hook(mlx_image, ));
            //printf("lh: %d, ds: %d, de:%d, h: %d",lineHeight, drawStart, drawEnd, sts->resolution.y);

            int wall_color = make_color(0, 255, 0, 0);
            int floor_color = make_color(0, 70, 70, 70);
            int roof_color = make_color(0, 0, 255, 255);

            if (side == 1)
            {
                wall_color = wall_color / 2;
            }

            verticalStripe(sts->image_data, x, 0, drawStart, roof_color);
            verticalStripe(sts->image_data, x, drawStart, drawEnd, wall_color);
            verticalStripe(sts->image_data, x, drawEnd, 1079, floor_color);

            x++;
        }
        printf("\n");
//        int color = make_color(0, 255, 0, 0);
//        for (int c = 200; c <= 600; c++)
//            verticalStripe(sts->image_data, c, 200, 600, color);

    create_image_windows(sts->resolution.x, sts->resolution.y, sts->image_data, mlx); 
    }

   

