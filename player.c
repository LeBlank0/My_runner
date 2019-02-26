/*
** EPITECH PROJECT, 2018
** player
** File description:
** moving player
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

void running(sfRenderWindow *window, player_t *play)
{
    float anim = sfTime_asSeconds(sfClock_getElapsedTime(play->clock_running));

    sfSprite_setTextureRect(play->running_sprite, play->rectrun);
    sfRenderWindow_drawSprite(window, play->running_sprite, NULL);
    if (anim > 0.1) {
        play->rectrun.left += 84;
        sfClock_restart(play->clock_running);
    }
    if (play->rectrun.left == 672)
        play->rectrun.left = 0;
}

void jumping(sfRenderWindow *window, player_t *play)
{
    float anim = sfTime_asSeconds(sfClock_getElapsedTime(play->clock_jumping));

    sfSprite_setTextureRect(play->jumping_sprite, play->rectjump);
    sfRenderWindow_drawSprite(window, play->jumping_sprite, NULL);
    if (anim > 0.02 && (play->speed == -6 || play->speed == 0
        || play->speed == 6))
        play->rectjump.left += 84;
    if (anim > 0.02) {
        sfSprite_move(play->jumping_sprite,
        (sfVector2f){0, play->speed});
        sfClock_restart(play->clock_jumping);
        play->speed += 1;
    }
    if (play->speed == 26) {
        play->rectjump.left = 0;
        play->speed = 0;
        play->jumpstatus = 0;
    }
}

void player(sfRenderWindow *window, player_t *play, text_t *tex)
{
    if (play->jumpstatus == 1)
        jumping(window, play);
    else
        running(window, play);
    text(window, tex);
}
