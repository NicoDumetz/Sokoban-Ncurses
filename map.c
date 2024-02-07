/*
** EPITECH PROJECT, 2023
** set map
** File description:
** map of ncurses in array
*/
#include "include/my_sokoban.h"

static int len_tab(char *str)
{
    int compt = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n')
            compt++;
    }
    return compt;
}

static void set_rang(char **map, char *str, int i, int *j)
{
        for (int k = 0; str[*j] != '\n'; (*j)++) {
            map[i][k] = str[*j];
            k++;
        }
}

static char **set_map(char *str)
{
    char **map;
    int j = 0;
    int i = 0;
    int k = 0;
    int compt = 0;

    map = malloc(sizeof(char *) * (len_tab(str) + 1));
    for (i; str[j] != '\0'; i++) {
        for (k; str[k] != '\n';k++)
            compt++;
        map[i] = malloc(sizeof(char) * (compt + 1));
        set_rang(map, str, i, &j);
        map[i][compt] = '\0';
        j++;
        k++;
        compt = 0;
    }
    map[i] = 0;
    return map;
}

char **get_map(char **av)
{
    struct stat file;
    int fd;
    int size;
    char *str;
    int rsize;

    if (stat(av[1], &file) == -1)
        exit(84);
    size = file.st_size;
    if (size == 0)
        exit(84);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        exit(84);
    str = malloc(sizeof(char) * size + 1);
    rsize = read(fd, str, size);
    str[rsize] = '\0';
    close(fd);
    return set_map(str);
}

void free_array(char **world)
{
    for (int i = 0; world[i]; i++) {
        free(world[i]);
    }
    free(world);
}

int number_point(char **map)
{
    int nbr = 0;

    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            nbr += map[i][j] == 'O' ? 1 : 0;
        }
    }
    return nbr;
}

static void set_struct(char **map, struct player *flags, int i, int j)
{
    if (map[i][j] == 'O') {
        flags->x = j;
        flags->y = i;
    }
}

struct player *get_point(char **map, struct player *flags)
{
    int nbr = number_point(map);
    int k = 0;

    flags = malloc(sizeof(struct player) * (nbr + 1));
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            set_struct(map, &flags[k], i , j);
            k += map[i][j] == 'O' ? 1 : 0;
        }
    }
    flags[nbr].x = -1;
    return flags;
}
