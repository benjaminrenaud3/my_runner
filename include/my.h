/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** struct for the game
*/

#ifndef MY_H_
#define MY_H_

#include "struct.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

background_t *create_back(const char *path_to_spritesheet);
block_t *create_block(const char *path_to_spritesheet, enum type_s _type);
carac_t *create_perso(const char *sprite, enum persoc_s _corb, int x, int y);
list_t *init_list (list_t *list, background_t *back);
int touchcollison(runer_t *run, int dir, int cpt);
void perso_interaction(runer_t *run);
int stop(runer_t *run);
void gameloop(runer_t *run);
void move_back(sfRenderWindow *window, list_t *list);
void display_all(runer_t *run);
void print_score(runer_t *run);
void create_score(runer_t *run);
void move_perso(perso_t *perso);
void move_block(block_t **mapblock, int nbelem);
void fill_tab(runer_t *run);
void create_tab_block(runer_t *run, char **argv);
void create_tab_perso(runer_t *run);
void settabposition(runer_t *run);
void my_putstr(char *str);
void usage(void);
int main (int argc, char **argv);
int error (int argc, char **argv);
int errormap(runer_t *run);

#endif
