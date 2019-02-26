/*
** EPITECH PROJECT, 2018
** background_set
** File description:
** running game background_set
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

void background_set_bis(back_t *back)
{
    back->clock_background = sfClock_create();
    back->move_back1 = 0;
    back->move_back2 = 0;
    back->move_back3 = 0;
    back->move_back4 = 0;
    back->move_ground = 0;
}

void background_set(back_t *back)
{
    back->back0_texture = sfTexture_createFromFile("sprite/Back0.png", NULL);
    back->back0_sprite = sfSprite_create();
    sfSprite_setTexture(back->back0_sprite, back->back0_texture, sfTrue);
    back->back1_texture = sfTexture_createFromFile("sprite/Back1.png", NULL);
    back->back1_sprite = sfSprite_create();
    sfSprite_setTexture(back->back1_sprite, back->back1_texture, sfTrue);
    back->back2_texture = sfTexture_createFromFile("sprite/Back2.png", NULL);
    back->back2_sprite = sfSprite_create();
    sfSprite_setTexture(back->back2_sprite, back->back2_texture, sfTrue);
    back->back3_texture = sfTexture_createFromFile("sprite/Back3.png", NULL);
    back->back3_sprite = sfSprite_create();
    sfSprite_setTexture(back->back3_sprite, back->back3_texture, sfTrue);
    back->back4_texture = sfTexture_createFromFile("sprite/Back4.png", NULL);
    back->back4_sprite = sfSprite_create();
    sfSprite_setTexture(back->back4_sprite, back->back4_texture, sfTrue);
    back->ground_texture = sfTexture_createFromFile("sprite/Ground.png", NULL);
    back->ground_sprite = sfSprite_create();
    sfSprite_setTexture(back->ground_sprite, back->ground_texture, sfTrue);
    background_set_bis(back);
}
