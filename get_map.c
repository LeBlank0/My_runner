/*
** EPITECH PROJECT, 2018
** get_map
** File description:
** getting the map
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
#include <fcntl.h>
#include <unistd.h>

char *my_cat(char *dest, char const *src, int nb)
{
    char *res = malloc(sizeof(char) *(nb + 1));
    int i = 0;
    int w = 0;

    while (dest[i] != '\0') {
        res[i] = dest[i];
        i++;
    }
    while (src[w] != '\0') {
        res[i + w] = src[w];
        w++;
    }
    res[i + w] = '\0';
    return (res);
}

int check(char *buff)
{
    int a = 0;

    for (int i = (1 - 1); i != - 1; i--) {
        if (buff[i] == '\0')
            a = 84;
    }
    return (a);
}

char *clear_str(char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++)
        buff[i] = '\0';
    return (buff);
}

char *get_file(int file)
{
    int nb = 1;
    char *buffer = malloc(sizeof(char) * 1);
    char *buff = malloc(sizeof(char) * (2));

    buffer[0] = '\0';
    read(file, buff, 1);
    buff[1] = '\0';
    buffer = my_cat(buffer, buff, nb);
    while (check(buff) != 84) {
        buff = clear_str(buff);
        read(file, buff, 1);
        buff[1] = 0;
        nb++;
        buffer = my_cat(buffer, buff, nb);
    }
    return (buffer);
}

char *get_map(char *str)
{
    int file = open(str, O_RDONLY);
    char *map = get_next_line(file);

    close(file);
    return (map);
}
