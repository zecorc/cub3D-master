/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iwu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:52:29 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/07 20:02:54 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"
#include <stdio.h>

void    verticalStripe(t_img_data *img, int x, int drawStart, int drawEnd, int color)
{  
    while (drawStart <= drawEnd)
    {
        mlx_pixel_put_fast(img, x, drawStart, color);
        drawStart++;
    }
}

t_img_data  *create_image(int size_x, int size_y, void *mlx_image)
{
    t_img_data *img;
    if (!(img = (t_img_data*)malloc(sizeof(t_img_data))))
        return(0);
    
    mlx_image = mlx_init();
    img->image = mlx_new_image(mlx_image, size_x, size_y);
    img->address= mlx_get_data_addr(img->image, &img->bits_per_pixel, &img->line_lenght, &img->endian);
    return (img);
}
/*
void    create_image_windows(void   *mlx_windows, t_img_data *img_data, void *mlx_image)
{
    //mlx_loop_hook(mlx, render_next_frame, YourStruct);
    
    //mlx_loop(mlx_image);
}
*/
void mlx_pixel_put_fast(t_img_data *img_data, int x, int y, int color)
{
    char *destination;

    destination = img_data->address + (y * img_data->line_lenght + x * (img_data->bits_per_pixel / 8));
    *(unsigned int*)destination = color;
}

int		make_color(int t, int r, int g, int b)
{
    t = (t > 255) ? 255 : (t < 0) ? 0 : (int)t;
    r = (r > 255) ? 255 : (r < 0) ? 0 : (int)r;
    g = (g > 255) ? 255 : (g < 0) ? 0 : (int)g;
    b = (b > 255) ? 255 : (b < 0) ? 0 : (int)b;
	return(t << 24 | r << 16 | g << 8 | b);
}

//move forward if no wall in front of you
void on_w(t_alls *sts)
{
   if(sts->map[(int)(sts->move.posY)][(int)(sts->move.posX + sts->move.dirX * MSPD)] == '0')
    {
        //printf("test\n");
        sts->move.posX += sts->move.dirX * MSPD;
    }
    if(sts->map[(int)(sts->move.posY + sts->move.dirY * MSPD)][(int)(sts->move.posX)] == '0')
    {
        // printf("test\n");
        sts->move.posY += sts->move.dirY * MSPD;
    }
}
//move backwards if no wall behind you
void on_s(t_alls *sts)
{
    printf("s\n");
    if(sts->map[(int)(sts->move.posY)][(int)(sts->move.posX - sts->move.dirX * MSPD)] == 0) sts->move.posX -= sts->move.dirX * MSPD;
    if(sts->map[(int)(sts->move.posY - sts->move.dirY * MSPD)][(int)(sts->move.posX)] == 0) sts->move.posY -= sts->move.dirY * MSPD;
}

void on_a(t_alls *sts)
{
    if(sts->map[(int)(sts->move.posY)][(int)(sts->move.posX + sts->move.dirX * MSPD)] == 0) sts->move.posX += sts->move.dirX * MSPD;
    if(sts->map[(int)(sts->move.posY + sts->move.dirY * MSPD)][(int)(sts->move.posX)] == 0) sts->move.posY += sts->move.dirY * MSPD;
}

void on_d(t_alls *sts)
{
    if(sts->map[(int)(sts->move.posY)][(int)(sts->move.posX - sts->move.dirX * MSPD)] == 0) sts->move.posX -= sts->move.dirX * MSPD;
    if(sts->map[(int)(sts->move.posY - sts->move.dirY * MSPD)][(int)(sts->move.posX)] == 0) sts->move.posY -= sts->move.dirY * MSPD;
}

//rotate to the right
void on_right(t_alls *sts)
{
    //both camera direction and camera plane must be rotated
    double oldDirX = sts->move.dirX;
    sts->move.dirX = sts->move.dirX * cos(-RSPD) - sts->move.dirY * sin(-RSPD);
    sts->move.dirY = oldDirX * sin(-RSPD) + sts->move.dirY * cos(-RSPD);
    double oldPlaneX = sts->move.planeX;
    sts->move.planeX = sts->move.planeX * cos(-RSPD) - sts->move.planeY * sin(-RSPD);
    sts->move.planeY = oldPlaneX * sin(-RSPD) + sts->move.planeY * cos(-RSPD);
}
//rotate to the left
void on_left(t_alls *sts)
{
    //both camera direction and camera plane must be rotated
    double oldDirX = sts->move.dirX;
    sts->move.dirX = sts->move.dirX * cos(RSPD) - sts->move.dirY * sin(RSPD);
    sts->move.dirY = oldDirX * sin(RSPD) + sts->move.dirY * cos(RSPD);
    double oldPlaneX = sts->move.planeX;
    sts->move.planeX = sts->move.planeX * cos(RSPD) - sts->move.planeY * sin(RSPD);
    sts->move.planeY = oldPlaneX * sin(RSPD) + sts->move.planeY * cos(RSPD);
}
  
int render_next_frame(t_alls *sts)
{
        sts->frame++;
        int x;
        
        /* prendere informazione dalla struttura */
        
        x = 0;

        printf("[%f + %f * mspd] = %d , [%f] = %d, -> %d\n",sts->move.posX,sts->move.dirX,(int)(sts->move.posX + sts->move.dirX * MSPD),sts->move.posY,(int)(sts->move.posY),sts->map[(int)(sts->move.posX + sts->move.dirX * MSPD)][(int)(sts->move.posY)]);
        //printf("map[4][2]=%d\n",sts->map[4][2]);  
        /*  
       int col = 0;
        int rig = 0;
         while(rig < 8)
         {
             col =0;
             while (col < 9)
             {
                 printf("%c", sts->map[rig][col]);
                 col++;
             }
             printf("\n");
             rig++;
         }
         printf("\n");
         */
        /*
        if(sts->map[(int)(sts->move.posY)][(int)(sts->move.posX + sts->move.dirX * MSPD)] == '0')
        {
            //printf("test\n");
            sts->move.posX += sts->move.dirX * MSPD;
        }
        if(sts->map[(int)(sts->move.posY + sts->move.dirY * MSPD)][(int)(sts->move.posX)] == '0')
        {
           // printf("test\n");
            sts->move.posY += sts->move.dirY * MSPD;
        }
        */
        while (x < sts->resolution.x)
        {
            //printf("0\n");
            //calcolo posizione e direzione del raggio 
            double cameraX = 2 * x / (double)sts->resolution.x - 1;

            double raydirX = sts->move.dirX + sts->move.planeX * cameraX;
            double raydirY = sts->move.dirY + sts->move.planeY * cameraX;
            //printf("x: %d raydirX: %f raydirY: %f sts->move.dirX: %f sts->move.dirY: %f\n", x, raydirX, raydirY, sts->move.dirX, sts->move.dirY); 
            if((sts->move.dirX <= (sqrtf(2) / 2) && sts->move.dirY >= -(sqrtf(2) / 2)) && (sts->move.dirX <= -(sqrtf(2) / 2)))
                raydirY *= -1;
            if((sts->move.dirX <= (sqrtf(2) / 2) && sts->move.dirY >= -(sqrtf(2) / 2)) && (sts->move.dirY >= (sqrtf(2) / 2)))
                raydirX *= -1;
            ///printf("x: %d raydirX: %f raydirY: %f sts->move.dirX: %f sts->move.dirY: %f\n\n", x, raydirX, raydirY, sts->move.dirX, sts->move.dirY);
            //box della mappa in cui siamo 
            int mapX = (int)sts->move.posX;
            int mapY = (int)sts->move.posY;

            //lunghezza del raggio dalla poszione corrente alla prossima linea x o y
            double  sideDistX;
            double  sideDistY;

            //lunghezza del raggio da una lindea x o y alla prossima linea x o y
            double deltaDistX = (raydirX == 0) ? 1e30 : fabs(1 / raydirX);
            double deltaDistY = (raydirY == 0) ? 1e30 : fabs(1 / raydirY);
            double perpWallDist;
            
            int hit = 0; //hit controller
            int side; // NS-EW controller
            //printf("1\n");
            //step e sideDist iniziale
            int stepX = 0;
            int stepY = 0;
            if (raydirX < 0)
            {
                stepX = -1;
                sideDistX = (sts->move.posX - (double)mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = ((double)mapX + 1.0 - sts->move.posX) * deltaDistX;
            }
            if (raydirY < 0)
            {
                stepY = -1;
                sideDistY = (sts->move.posY - (double)mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = ((double)mapY + 1.0 - sts->move.posY) * deltaDistY;
            }
            //printf("deltaX %f sidedistX %f sidedistY %f\n",deltaDistX, sideDistX, sideDistY);
            //DDA
            //printf("2\n");
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
            //printf("3\n");
            //printf ("raydirY %f stepX %d stepY %d mapX %d mapY %d deltaX %f deltaY %f sideX %f sideY %f\n",raydirY, stepX, stepY, mapX, mapY, deltaDistX, deltaDistY, sideDistX, sideDistY);
            if (side == 0)
                perpWallDist = (sideDistX - deltaDistX);
            else
                perpWallDist = (sideDistY - deltaDistY);
            //printf("side %d walldist: %f sideX %f deltaX %f sideY %f deltaY %f\n", side, perpWallDist, sideDistX, deltaDistX, sideDistY, deltaDistY);
            //altezza della linea da disegnare
            //printf("4\n");
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
            //printf("x: %d cameraX %f raydirX %f raydirY %f sideDistX: %f sideDistY: %f distanza: %f\n", x, cameraX, raydirX, raydirY, sideDistX, sideDistY, perpWallDist);
            //printf("5\n");
            // mlx_key_hook(mlx_image, ));
            // printf("lh: %d, ds: %d, de:%d, h: %d",lineHeight, drawStart, drawEnd, sts->resolution.y);
            int wall_color = make_color(0, 255, 0, 0);
            int floor_color = make_color(0, 70, 70, 70);
            int roof_color = make_color(0, 0, sts->frame%255, 0);
            //printf("clr: %d\n", sts->frame%255);

            if (side == 1)
            {
                wall_color = wall_color / 2;
            }
            //printf("6\n");
            verticalStripe(sts->image_data, x, 0, drawStart, roof_color);
            verticalStripe(sts->image_data, x, drawStart, drawEnd, wall_color);
            verticalStripe(sts->image_data, x, drawEnd, 1079, floor_color);
            
            x++;
            //printf("7\n");
        }
        //printf("clr: %d\n", sts->frame%255);
        //verticalStripe(sts->image_data, 25, 0, 500, make_color(0, 255, 255, 255));
        mlx_put_image_to_window(sts->wndw.mlx_image, sts->wndw.mlx_windows, sts->image_data->image, 0, 0);
        return(0);
}

/*
int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}
*/
