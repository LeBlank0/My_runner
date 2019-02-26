/*
** EPITECH PROJECT, 2018
** destroy
** File description:
** running game destroy
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

void destroytext(text_t *tex)
{
    sfClock_destroy(tex->timer);
    sfText_destroy(tex->text);
}

void destroymap(map_t *map, text_t *tex)
{
    sfTexture_destroy(map->spike_texture);
    for (int i = 0; i != map->nb; i++)
        sfSprite_destroy(map->spike_sprite[i]);
    sfClock_destroy(map->clock_spike);
    destroytext(tex);
}

void destroyplay(player_t *play, map_t *map, text_t *tex)
{
    sfSprite_destroy(play->running_sprite);
    sfSprite_destroy(play->jumping_sprite);
    sfTexture_destroy(play->running_texture);
    sfTexture_destroy(play->jumping_texture);
    sfClock_destroy(play->clock_running);
    sfClock_destroy(play->clock_jumping);
    sfMusic_destroy(play->jumpsound);
    destroymap(map, tex);
}

void destroy(back_t *back, player_t *play, map_t *map, text_t *tex)
{
    sfSprite_destroy(back->back0_sprite);
    sfSprite_destroy(back->back1_sprite);
    sfSprite_destroy(back->back2_sprite);
    sfSprite_destroy(back->back3_sprite);
    sfSprite_destroy(back->back4_sprite);
    sfSprite_destroy(back->ground_sprite);
    sfTexture_destroy(back->back0_texture);
    sfTexture_destroy(back->back1_texture);
    sfTexture_destroy(back->back2_texture);
    sfTexture_destroy(back->back3_texture);
    sfTexture_destroy(back->back4_texture);
    sfTexture_destroy(back->ground_texture);
    sfClock_destroy(back->clock_background);
    destroyplay(play, map, tex);
}
