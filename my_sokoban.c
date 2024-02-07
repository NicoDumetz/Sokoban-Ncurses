/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** placeholder
*/

#include "include/my_printf.h"
#include "include/my_sokoban.h"


void moove(char **map, struct player *player, int ch, struct player *flags)
{
    if (ch == KEY_UP && player->x > 0 && map[player->x - 1][player->y] != '#')
        go_up(map, player);
    if (ch == KEY_DOWN && map[player->x + 1][player->y] != '#')
        down(map, player);
    if (ch == KEY_LEFT && map[player->x][player->y - 1] != '#')
        left(map, player, flags);
    if (ch == KEY_RIGHT && map[player->x][player->y + 1] != '#')
        right(map, player);
}

void write_point(char **map, struct player *flags)
{
    for (int i = 0; flags[i].x != -1; i++) {
        map[flags[i].y][flags[i].x] = map[flags[i].y][flags[i].x] != 'X' &&
        map
        [flags[i].y][flags[i].x] != 'P' ? 'O' : map[flags[i].y][flags[i].x];
    }
}

static int winnable(char **map, struct player *flags, struct player *player)
{
    int win = 0;

    if (number_point(map) == 0) {
        win = 1;
        for (int i = 0; flags[i].x != -1; i++) {
            win = flags[i].x == player->y && flags[i].y == player->x ? 0 : win;
        }
        return win;
    }
    return win;
}

static int game(char **map, struct player *player, struct player *flags, char
    **cpy_map)
{
    int ch;

    clear();
    for (int i = 0; map[i]; i++)
        printw("%s\n", map[i]);
    refresh();
    if (winnable(map, flags, player) == 1)
        return 0;
    if (loose(map, flags, player) == 1)
        return 1;
    ch = getch();
    moove(map, player, ch, flags);
    write_point(map, flags);
    if (ch == 27)
        return 1;
    if (ch == ' ')
        map = cpy_array(map, cpy_map, player);
    refresh();
    return 5;
}

static int ncurses(char **map, struct player *player, struct player *flags,
    char **cpy_map)
{
    int win;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    while (true) {
        win = game(map, player, flags, cpy_map);
        if (win < 3)
            break;
    }
    endwin();
    return win;
}

void set_player(struct player *player, char **map)
{
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            player->x = map[i][j] == 'P' ? i : player->x;
            player->y = map[i][j] == 'P' ? j : player->y;
        }
    }
}

int my_sokoban(int ac, char **av)
{
    char **map = get_map(av);
    char **cpy_map = get_map(av);
    struct player player;
    struct player *flags = get_point(map, flags);
    int win;

    if (verify_map(map) == 84)
        return 84;
    set_player(&player, map);
    win = ncurses(map, &player, flags, cpy_map);
    free_array(map);
    free_array(cpy_map);
    return win;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0) {
        my_printf("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map file");
        my_printf("representing the warehouse map, containing ‘#’ for walls");
        my_printf(",\n          ‘P’ for the player, ‘X’ for boxes and ‘O’ ");
        my_printf("for storage locations.\n");
        return 0;
    }
    return my_sokoban(ac, av);
}
