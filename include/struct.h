/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** struct for the game
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct background_s {

	sfSprite *my_back;
	sfTexture *tback;
	sfVector2f posback;
	sfIntRect rectback;

}background_t;

enum type_s {
	BRICK = 0,
	IRON,
};

typedef struct block_s {

	enum type_s type;
	sfSprite *my_block;
	sfTexture *tblock;
	sfVector2f posblock;
	sfIntRect rectblock;

}block_t;

enum persoc_s {
	COOL = 0,
	BAD,
};

typedef struct carac_s {

	enum persoc_s corb;
	sfSprite *my_perso;
	sfTexture *tperso;
	sfVector2f posperso;
	sfIntRect rectperso;

}carac_t;

typedef struct perso_s {

	carac_t *carac;
	carac_t **tabperso;

}perso_t;

typedef struct list_s {

	background_t *back;
	struct list_s *next;

}list_t;

typedef struct obj_s {

	block_t *block;
	block_t **mapblock;
}obj_t;

typedef struct runer_s {
	sfRenderWindow *window;
	sfEvent event;
	sfSprite *my_block;
	sfTexture *tblock;
	sfMusic *sound;
	sfText *score;
	sfText *score2;
	sfFont *font;
	int mapisok;
	int cpt_score;
	int xmax;
	int bleftmax;
	int nbelem;
	int nbperso;
	int posx;
	int posy;
	char *map;
	perso_t *perso;
	obj_t *obj;
	list_t *list;
}runer_t;

#endif
