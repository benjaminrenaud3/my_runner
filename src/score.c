/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** score
*/

#include "my.h"

int strlen_int(int cpt)
{
	int length = 0;
	while (cpt != 0) {
		length += 1;
		cpt = cpt / 10;
	}
	return (length);
}

int power(int cpt, int cpt2)
{
	int i = 0;
	int save = 1;

	if (cpt2 == 0)
		return (1);

	while (i < cpt2) {
		save = save * cpt;
		i++;
	}
	return (save);
}

char *create_str_score(runer_t *run)
{
	int cpt = strlen_int(run->cpt_score);
	int cpt2 = 0;

	char *str = malloc(sizeof(char) * (cpt + 1));
	while (cpt2 < cpt + 1) {
		str[cpt2] =
		((int)(run->cpt_score / power(10, cpt - cpt2)) % 10) + 48;
		cpt2 += 1;
	}
	str[cpt2] = '\0';
	return (str);
}

void print_score(runer_t *run)
{
	sfText_setString(run->score2, create_str_score(run));
	sfRenderWindow_drawText(run->window, run->score, NULL);
	sfRenderWindow_drawText(run->window, run->score2, NULL);
}

void create_score(runer_t *run)
{
	run->score = sfText_create();
	run->score2 = sfText_create();
	run->font = sfFont_createFromFile("media/script.ttf");

	sfText_setFont(run->score, run->font);
	sfText_setCharacterSize(run->score, 40);
	sfText_setFont(run->score2, run->font);
	sfText_setCharacterSize(run->score2, 40);
	sfText_setPosition(run->score, (sfVector2f){10, 10});
	sfText_setPosition(run->score2, (sfVector2f){160, 10});
	sfText_setString(run->score, "score :");
}
