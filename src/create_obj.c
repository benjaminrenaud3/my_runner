/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** boucle principal
*/

#include "struct.h"
#include "my.h"

background_t *create_back(const char *path_to_spritesheet)
{
	background_t *fond = malloc(sizeof(background_t));
	fond->my_back = sfSprite_create();
	fond->tback = sfTexture_createFromFile(path_to_spritesheet, NULL);
	sfSprite_setTexture (fond->my_back, fond->tback, sfTrue);
	fond->posback.x = 0;
	fond->posback.y = 0;
	sfSprite_setPosition(fond->my_back, fond->posback);
	return (fond);
}

block_t *create_block(const char *path_to_spritesheet, enum type_s _type)
{
	block_t *block = malloc(sizeof(block_t));
	block->type = _type;
	block->my_block = sfSprite_create();
	block->tblock = sfTexture_createFromFile(path_to_spritesheet, NULL);
	sfSprite_setTexture (block->my_block, block->tblock, sfTrue);
	block->posblock.x = 0;
	block->posblock.y = 0;
	block->rectblock.left = 0;
	block->rectblock.top = 0;
	block->rectblock.width = 64;
	block->rectblock.height = 64;
	sfSprite_setPosition(block->my_block, block->posblock);
	return (block);
}

carac_t *create_perso(const char *sprite, enum persoc_s _corb, int x, int y)
{
	carac_t *carac = malloc(sizeof(carac_t));
	carac->corb = _corb;
	carac->my_perso = sfSprite_create();
	carac->tperso = sfTexture_createFromFile(sprite, NULL);
	sfSprite_setTexture (carac->my_perso, carac->tperso, sfTrue);
	carac->posperso.x = x;
	carac->posperso.y = y;
	carac->rectperso.left = 0;
	carac->rectperso.top = 0;
	carac->rectperso.width = 120;
	carac->rectperso.height = 120;
	sfSprite_setTextureRect(carac->my_perso, carac->rectperso);
	sfSprite_setPosition(carac->my_perso, carac->posperso);
	return (carac);
}

list_t *init_list (list_t *list, background_t *back)
{
	list_t *new = malloc(sizeof(list_t));
	new->next = list;
	list = new;
	new->back = back;
	return (list);
}
