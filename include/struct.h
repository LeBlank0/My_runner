/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** struct
*/

#ifndef LISTE_H_
#define LISTE_H_

typedef struct back_s
{
    sfTexture *back0_texture;
    sfTexture *back1_texture;
    sfTexture *back2_texture;
    sfTexture *back3_texture;
    sfTexture *back4_texture;
    sfTexture *ground_texture;
    sfSprite *back0_sprite;
    sfSprite *back1_sprite;
    sfSprite *back2_sprite;
    sfSprite *back3_sprite;
    sfSprite *back4_sprite;
    sfSprite *ground_sprite;
    float move_back1;
    float move_back2;
    float move_back3;
    float move_back4;
    float move_ground;
    sfClock *clock_background;
} back_t;

typedef struct player_s
{
    int jumpstatus;
    int speed;
    sfTexture *running_texture;
    sfTexture *jumping_texture;
    sfSprite *running_sprite;
    sfSprite *jumping_sprite;
    sfIntRect rectrun;
    sfIntRect rectjump;
    sfClock *clock_running;
    sfClock *clock_jumping;
    sfMusic *jumpsound;
} player_t;

typedef struct map_s
{
    sfTexture *spike_texture;
    sfSprite **spike_sprite;
    sfIntRect *rect_spike;
    sfClock *clock_spike;
    float pos_spike;
    float move_spike;
    int nb;
} map_t;

typedef struct text_s
{
    sfFont *font;
    sfText *text;
    sfClock *timer;
    int score;
} text_t;

void background_set(back_t *back);
void player_set(player_t *play);
char *get_map(char *str);
void map_set(map_t *map, char *the_map);
void set_map(sfRenderWindow *window, map_t *map);
void move(sfRenderWindow *window, back_t *back);
void player(sfRenderWindow *window, player_t *play, text_t *text);
void coll(sfRenderWindow *window, player_t *play, map_t *map);
void text_set(text_t *text);
void text(sfRenderWindow *window, text_t *text);
void destroy(back_t *back, player_t *play, map_t *map, text_t *tex);

#endif
