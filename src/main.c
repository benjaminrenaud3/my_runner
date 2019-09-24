/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** boucle principal
*/

#include "struct.h"
#include "my.h"

void my_putstr(char *str)
{
	int var = 0;

	while (str[var] != '\0') {
		write(1, &str[var], 1);
		var = var + 1;
	}
}

void usage(void)
{
	my_putstr("\t\t\tTRUCKER'S\n\t\t\t\tDELIGHT\n\t\t\t\t\tGAME\n\n");
	my_putstr("usage : ./my_runner map.txt\n\n");
	my_putstr("interaction : SPACE for jump\n");
	my_putstr("\tyou die if you hit a wall or if you fall outside the map");
	my_putstr("\n\tyou win if you finish a map");
	my_putstr("\n\ncreate map : file .txt with 16 lines\n");
	my_putstr("\t\t. for nothing\n");
	my_putstr("\t\t1 for a wall\n");
	my_putstr("\t\t2 for a background block\n\n");
	my_putstr("\t\t\tENJOY\n\n");
	my_putstr("look Trucker's Delight on youtube\n");
}

void create_parallax(runer_t *run)
{
	background_t *fond2;
	background_t *fond3;
	fond2 = create_back("media/fond.png");
	fond3 = create_back("media/cielend.jpg");
	run->list = init_list (run->list, fond2);
	run->list = init_list (run->list, fond3);
}

sfMusic *initprog(runer_t *run, char **argv, sfMusic *music)
{
	run->map = malloc(sizeof(char) * (10001));
	run->obj = malloc(sizeof(obj_t));
	run->perso = malloc(sizeof(perso_t));
	run->bleftmax = 0;
	run->mapisok = 0;
	run->sound = sfMusic_createFromFile("media/jump.ogg");
	music = sfMusic_createFromFile("media/trucker.ogg");
	sfMusic_play(music);
	create_tab_block(run, argv);
	if (run->mapisok == 84)
		return (music);
	create_tab_perso(run);
	create_score(run);
	settabposition(run);
	create_parallax(run);
	return (music);
}

int main (int argc, char **argv)
{
	sfMusic *music;
	runer_t *run = malloc(sizeof(runer_t));
	sfVideoMode mode = {1920, 1080, 32};
	if (error(argc, argv) == 84)
		return (84);
	music = initprog(run, argv, music);
	if (run->mapisok == 84) {
		sfMusic_destroy(music);
		sfMusic_destroy(run->sound);
		return (84);
	}
	run->window = sfRenderWindow_create
	(mode, "SFML window", sfResize | sfClose, NULL);
	if (!run->window)
		return (0);
	gameloop(run);
	sfMusic_destroy(music);
	sfMusic_destroy(run->sound);
	return (0);
}
