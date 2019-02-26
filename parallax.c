/*
** EPITECH PROJECT, 2018
** parallax
** File description:
** running game parallax
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

void move_back_bis(sfRenderWindow *window, back_t *back)
{
    back->move_back3 -= 4;
    sfSprite_setPosition(back->back3_sprite,
    (sfVector2f){back->move_back3, 0});
    sfRenderWindow_drawSprite(window, back->back3_sprite, NULL);
    if (back->move_back3 <= -1920)
        back->move_back3 = 0;
    back->move_back4 -= 5;
    sfSprite_setPosition(back->back4_sprite,
    (sfVector2f){back->move_back4, 0});
    sfRenderWindow_drawSprite(window, back->back4_sprite, NULL);
    if (back->move_back4 <= -1920)
        back->move_back4 = 0;
    back->move_ground -= 6;
    sfSprite_setPosition(back->ground_sprite,
    (sfVector2f){back->move_ground, 895});
    sfRenderWindow_drawSprite(window, back->ground_sprite, NULL);
    if (back->move_ground <= -1920)
        back->move_ground = 0;
}

void move_back(sfRenderWindow *window, back_t *back)
{
    back->move_back1 -= 2;
    sfSprite_setPosition(back->back1_sprite,
    (sfVector2f){back->move_back1, 0});
    sfRenderWindow_drawSprite(window, back->back1_sprite, NULL);
    if (back->move_back1 <= -1920)
        back->move_back1 = 0;
    back->move_back2 -= 3;
    sfSprite_setPosition(back->back2_sprite,
    (sfVector2f){back->move_back2, 0});
    sfRenderWindow_drawSprite(window, back->back2_sprite, NULL);
    if (back->move_back2 <= -1920)
        back->move_back2 = 0;
    move_back_bis(window, back);
}

void move(sfRenderWindow *window, back_t *back)
{
    float anim = sfTime_asSeconds(sfClock_getElapsedTime
    (back->clock_background));

    if (anim > 0.01) {
        move_back(window, back);
        sfClock_restart(back->clock_background);
    }
}
