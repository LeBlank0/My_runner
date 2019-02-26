/*
** EPITECH PROJECT, 2018
** collision
** File description:
** runner collision between player and ennemies
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Network.h>
#include "include/my.h"
#include "include/struct.h"
#include <stdlib.h>
#include <stdio.h>

void coll(sfRenderWindow *window, player_t *play, map_t *map)
{
    sfFloatRect run = sfSprite_getGlobalBounds(play->running_sprite);
    sfFloatRect jump = sfSprite_getGlobalBounds(play->jumping_sprite);
    sfFloatRect collideBox;

    for (int i = 0; i < map->nb; i++) {
        collideBox = sfSprite_getGlobalBounds(map->spike_sprite[i]);
        jump.left += 20;
        jump.height -= 60;
        jump.width -= 40;
        run.left += 10;
        run.width -= 30;
        if (sfFloatRect_intersects(&run, &collideBox, NULL)
            && !play->jumpstatus)
            sfRenderWindow_close(window);
        else if (sfFloatRect_intersects(&jump, &collideBox, NULL)
            && play->jumpstatus)
            sfRenderWindow_close(window);
    }
}
