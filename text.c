/*
** EPITECH PROJECT, 2018
** text
** File description:
** runner score display
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

void text(sfRenderWindow *window, text_t *tex)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(tex->timer));

    sfText_setString(tex->text, my_itoa(tex->score));
    sfRenderWindow_drawText(window, tex->text, NULL);
    if (time >= 0.2) {
        tex->score += 1;
        sfClock_restart(tex->timer);
    }
}
