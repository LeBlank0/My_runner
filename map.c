/*
** EPITECH PROJECT, 2018
** map
** File description:
** running game map
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

void inf(sfRenderWindow *window, map_t *map)
{
    for (int i = 0; i != map->nb; i++) {
        sfSprite_move(map->spike_sprite[i],
        (sfVector2f){5600, 0});
        sfRenderWindow_drawSprite(window, map->spike_sprite[i], NULL);
    }
}

void set_map(sfRenderWindow *window, map_t *map)
{
    float anim = sfTime_asSeconds(sfClock_getElapsedTime(map->clock_spike));
    sfFloatRect first = sfSprite_getGlobalBounds(map->spike_sprite[0]);

    if (anim > 0.01) {
        if (first.left <= -5100)
            inf(window, map);
        for (int i = 0; i != map->nb; i++) {
            sfSprite_move(map->spike_sprite[i],
            (sfVector2f){map->move_spike, 0});
            sfRenderWindow_drawSprite(window, map->spike_sprite[i], NULL);
        }
        sfClock_restart(map->clock_spike);
    }
}
