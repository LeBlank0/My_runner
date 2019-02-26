/*
** EPITECH PROJECT, 2018
** text_set
** File description:
** running game text_set
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

void text_set(text_t *tex)
{
    tex->timer = sfClock_create();
    tex->font = sfFont_createFromFile("sprite/Jungle.otf");
    tex->text = sfText_create();
    tex->score = 0;
    sfText_setFont(tex->text, tex->font);
    sfText_setPosition(tex->text, (sfVector2f){10, 15});
    sfText_setCharacterSize(tex->text, 100);
}
