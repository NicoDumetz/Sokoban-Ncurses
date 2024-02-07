/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** placeholder
*/


#include "include/my_sokoban.h"

void moove(char **map, struct player *player, int ch, struct player *flags)
{
    if (ch == KEY_UP && map[player->x - 1][player->y] != '#')
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

static int verify_x(char **map, int i, int j, struct player *flags)
{
    if (map[i][j] != 'X')
        return 0;
    for (int k = 0; flags[k].x != -1; k++) {
        if (flags[k].x == j && flags[k].y == i)
            return 0;
    }
    if (map[i + 1][j] == '#' && map[i][j - 1] == '#')
        return 1;
    if (map[i][j - 1] == '#' && map[i - 1][j] == '#')
        return 1;
    if (map[i - 1][j] == '#' && map[i][j + 1] == '#')
        return 1;
    if (map[i][j + 1] == '#' && map[i + 1][j] == '#')
        return 1;
}

static int loose(char **map, struct player *flags, struct player *player)
{
    int loose = 0;

    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            loose = verify_x(map, i, j, flags) == 1 ? 1 : loose;
        }
    }
    return loose;
}

static int game(char **map, struct player *player, struct player *flags)
{
    int ch;

    clear();
    for (int i = 0; map[i]; i++)
        printw("%s\n", map[i]);
    ch = getch();
    moove(map, player, ch, flags);
    write_point(map, flags);
    if (winnable(map, flags, player) == 1)
        return 0;
    if (loose(map, flags, player) == 1)
        return 1;
    if (ch == 27)
        return 1;
    refresh();
    return 5;
}

int ncurses(char **map, struct player *player, struct player *flags)
{
    int win;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    while (true) {
        win = game(map, player, flags);
        if (win < 3)
            break;
    }
    endwin();
    return win;
}

static void set_player(struct player *player, char **map)
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
    struct player player;
    struct player *flags = get_point(map, flags);
    int win;

    set_player(&player, map);
    win = ncurses(map, &player, flags);
    free_array(map);
    return win;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    return my_sokoban(ac, av);
}
