/*
** EPITECH PROJECT, 2018
** player_set
** File description:
** running game player_set
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

void player_set(player_t *play)
{
    play->clock_running = sfClock_create();
    play->clock_jumping = sfClock_create();
    play->running_texture = sfTexture_createFromFile("sprite/Run.png", NULL);
    play->running_sprite = sfSprite_create();
    sfSprite_setTexture(play->running_sprite, play->running_texture, sfTrue);
    sfSprite_setScale(play->running_sprite, (sfVector2f){2, 2});
    play->rectrun = (sfIntRect){0, 0, 84, 132};
    sfSprite_setTextureRect(play->running_sprite, play->rectrun);
    sfSprite_setPosition(play->running_sprite, (sfVector2f){150, 660});
    play->jumping_texture = sfTexture_createFromFile("sprite/Jump.png", NULL);
    play->jumping_sprite = sfSprite_create();
    sfSprite_setTexture(play->jumping_sprite, play->jumping_texture, sfTrue);
    play->rectjump = (sfIntRect){0, 0, 84, 144};
    sfSprite_setScale(play->jumping_sprite, (sfVector2f){2, 2});
    sfSprite_setTextureRect(play->jumping_sprite, play->rectjump);
    sfSprite_setPosition(play->jumping_sprite, (sfVector2f){150, 660});
    play->jumpstatus = 0;
    play->speed = 0;
}
