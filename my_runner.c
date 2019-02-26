/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** running game
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

void event(sfRenderWindow *window, player_t *play)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        if (event.key.code == sfKeySpace && play->jumpstatus != 1) {
            play->jumpsound = sfMusic_createFromFile("sprite/jump.ogg");
            sfMusic_play(play->jumpsound);
            play->jumpstatus = 1;
            play->speed = -25;
        }
    }
}

void call(sfRenderWindow *window, char *str)
{
    back_t *back = malloc(sizeof(*back));
    player_t *play = malloc(sizeof(*play));
    map_t *map = malloc(sizeof(*map));
    text_t *tex = malloc(sizeof(*text));
    char *the_map = get_map(str);

    background_set(back);
    player_set(play);
    map_set(map, the_map);
    text_set(tex);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, back->back0_sprite, NULL);
        event(window, play);
        move(window, back);
        set_map(window, map);
        player(window, play, tex);
        coll(window, play, map);
        sfRenderWindow_display(window);
    }
    destroy(back, play, map, tex);
}

int main(int ac, char**av)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "SFML window",
    sfResize | sfClose, NULL);
    sfMusic *jungle = sfMusic_createFromFile("sprite/jungle.ogg");

    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfMusic_play(jungle);
    sfMusic_setLoop(jungle, sfTrue);
    call(window, av[1]);
    sfRenderWindow_destroy(window);
    return (0);
}
