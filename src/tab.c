/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** boucle principal
*/

#include "struct.h"
#include "my.h"

void fill_tab(runer_t *run)
{
	int cpt = 0;
	int save = 0;

	for (; run->map[cpt] != '\0'; cpt++) {
		switch (run->map[cpt]) {
		case '1':
			run->obj->mapblock[save] = create_block
			("media/bloc.png", BRICK);
			save++;
			break;
		case '2':
			run->obj->mapblock[save] = create_block
			("media/acier.png", IRON);
			save++;
			break;
		}
	}
}

void create_tab_block(runer_t *run, char **argv)
{
	int fd;
	run->nbelem = 0;
	int cpt = 0;
	int save = 0;

	fd = open(argv[1], O_RDONLY);
	read(fd, run->map, 10000);
	run->map[10000] = '\0';
	if (errormap(run) == 84)
		run->mapisok = 84;
	for (; run->map[cpt] != '\0'; cpt++) {
		if (run->map[cpt] >= '1' && run->map[cpt] <= '9')
		run->nbelem++;
	}
	run->obj->mapblock = malloc(sizeof(block_t *) * (run->nbelem + 1));
	fill_tab(run);
}

void create_tab_perso(runer_t *run)
{
	run->nbperso = 1;
	int x = 10;
	int y = 0;

	run->perso->tabperso = malloc(sizeof(carac_t *) * (run->nbperso + 1));
	run->perso->tabperso[0] = create_perso("media/perso.png", COOL, x, y);
}

void settabposition2(runer_t *run, int cpt, int cptset)
{
	if (run->map[cpt] == '1' && run->posx > run->xmax) {
		run->xmax = run->posx;
		run->bleftmax = cptset;
	}
	run->obj->mapblock[cptset]->posblock.x = run->posx;
	run->obj->mapblock[cptset]->posblock.y = run->posy;
	sfSprite_setPosition(run->obj->mapblock[cptset]->my_block,
	run->obj->mapblock[cptset]->posblock);
}

void settabposition(runer_t *run)
{
	int cpt = 0;
	int cptset = 0;
	run->posx = 0;
	run->posy = 0;

	while (run->map[cpt] != '\0') {
		if (run->map[cpt] == '.')
			run->posx += 64;
		else if (run->map[cpt] == '\n') {
			run->posx = 0;
			run->posy += 64;
		}
		else if (run->map[cpt] >= '1' && run->map[cpt] <= '9') {
			settabposition2(run, cpt, cptset);
			cptset++;
			run->posx += 64;
		}
		cpt++;
	}
}
