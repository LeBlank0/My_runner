/*
** EPITECH PROJECT, 2018
** map_set
** File description:
** running game map_set
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

void sprite(map_t *map, char *the_map, int i)
{
    static int nbr = 0;

    if (the_map[i] == ' ')
        map->pos_spike += 100;
    else if (the_map[i] == '1') {
        sfSprite_setPosition(map->spike_sprite[nbr],
        (sfVector2f){map->pos_spike, 810});
        map->pos_spike += 100;
        nbr++;
    }
}

void count(map_t *map, char *the_map)
{
    for (int i = 0; the_map[i] != '\0'; i++)
        if (the_map[i] == '1')
            map->nb++;
    map->spike_sprite = malloc(sizeof(sfSprite*) * map->nb);
    map->rect_spike = malloc(sizeof(sfIntRect) * map->nb);
    for (int i = 0; i != map->nb; i++) {
        map->spike_sprite[i] = sfSprite_create();
        sfSprite_setTexture(map->spike_sprite[i], map->spike_texture, sfTrue);
        map->rect_spike[i] = (sfIntRect){0, 0, 100, 112};
        sfSprite_setTextureRect(map->spike_sprite[i], map->rect_spike[i]);
    }
    for (int i = 0; the_map[i] != '\0'; i++)
        sprite(map, the_map, i);
}

void map_set(map_t *map, char *the_map)
{
    map->clock_spike = sfClock_create();
    map->spike_texture = sfTexture_createFromFile("sprite/Spike.png", NULL);
    map->nb = 0;
    map->move_spike = -6;
    map->pos_spike = 0;
    count(map, the_map);
}
