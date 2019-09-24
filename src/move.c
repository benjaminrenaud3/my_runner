/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** boucle principal
*/

#include "struct.h"
#include "my.h"

void move_back(sfRenderWindow *window, list_t *list)
{
	int cpt = 0;
	sfVector2f temp;
	float cst = 0.1;
	while (cpt < 2) {
		temp = list->back->posback;
		list->back->posback.x -= cst;
		sfSprite_setPosition(list->back->my_back, list->back->posback);
		sfRenderWindow_drawSprite(window, list->back->my_back, NULL);
		temp.x -= 1919;
		sfSprite_setPosition(list->back->my_back, temp);
		sfRenderWindow_drawSprite(window, list->back->my_back, NULL);
		if (list->back->posback.x <= 0)
			list->back->posback.x = 1920;
		list = list->next;
		cpt += 1;
		cst += 0.3;
	}
}

void display_all(runer_t *run)
{
	int cpt = 0;
	print_score(run);
	for (;cpt < run->nbelem;cpt++)
		sfRenderWindow_drawSprite
		(run->window, run->obj->mapblock[cpt]->my_block, NULL);
	cpt = 0;
	for (;cpt < run->nbperso;cpt++)
		sfRenderWindow_drawSprite
		(run->window, run->perso->tabperso[cpt]->my_perso, NULL);
}

void move_perso(perso_t *perso)
{
	static int cpt = 0;

	if (cpt < 5) {
		perso->tabperso[0]->rectperso.left += 120;
		cpt++;
	}
	else {
		perso->tabperso[0]->rectperso.left = 0;
		cpt = 0;
	}
	sfSprite_setTextureRect
	(perso->tabperso[0]->my_perso, perso->tabperso[0]->rectperso);
}

void move_block(block_t **mapblock, int nbelem)
{
	int cpt = 0;

	for (;cpt < nbelem;cpt++) {
		mapblock[cpt]->posblock.x -= 2;
		sfSprite_setPosition
		(mapblock[cpt]->my_block, mapblock[cpt]->posblock);
	}

}
