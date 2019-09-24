/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** boucle principal
*/

#include "struct.h"
#include "my.h"

int touchcollison(runer_t *run, int dir, int cpt)
{
	if (dir == 1) {
		if ((run->obj->mapblock[cpt]->type == BRICK)
		&& ((run->perso->tabperso[0]->posperso.y + 120)
		== (run->obj->mapblock[cpt]->posblock.y))
		&& (((run->perso->tabperso[0]->posperso.x + 60)
		>= (run->obj->mapblock[cpt]->posblock.x))
		&& ((run->perso->tabperso[0]->posperso.x + 60)
		<= (run->obj->mapblock[cpt]->posblock.x + 64))))
			return (1);
		else
			return (0);
	}
	else if (dir == 2) {
		if ((run->obj->mapblock[cpt]->type == BRICK)
		&& ((run->perso->tabperso[0]->posperso.x + 120)
		== (run->obj->mapblock[cpt]->posblock.x))
		&& (((run->perso->tabperso[0]->posperso.y + 60)
		>= (run->obj->mapblock[cpt]->posblock.y))
		&& ((run->perso->tabperso[0]->posperso.y + 60)
		<= (run->obj->mapblock[cpt]->posblock.y + 64))))
			return (1);
		else
			return (0);
	}
	return (0);
}
void perso_interaction(runer_t *run)
{
	static int collision = 0;
	int cpt = 0;
	run->cpt_score += 1;
	static int jump = 0;
	static int jump_verify = 0;
	static int keypressed = 0;

	while (run->obj->mapblock[cpt] != NULL) {
		if (touchcollison(run, 1, cpt) == 1) {
			collision = 1;
			jump_verify = 1;
			break;
		}
		else
			jump_verify = 0;
		cpt++;
	}
	if (jump_verify == 0)
		collision--;
	if (collision <= 0) {
		run->perso->tabperso[0]->posperso.y += 2;
		sfSprite_setPosition
		(run->perso->tabperso[0]->my_perso,
		run->perso->tabperso[0]->posperso);
	}
	if (sfKeyboard_isKeyPressed(sfKeySpace) && jump_verify == 1) {
		sfMusic_play(run->sound);
		keypressed = 1;
		collision = 70;
	}
	if ((keypressed == 1 && jump < 70)) {
		run->perso->tabperso[0]->posperso.y -= 2;
		sfSprite_setPosition
		(run->perso->tabperso[0]->my_perso,
		run->perso->tabperso[0]->posperso);
		jump++;
	}
	else if (jump >= 70) {
		jump = 0;
		jump_verify = 0;
		keypressed = 0;
	}
}

void fixscreen(runer_t *run, char const *path)
{
	background_t *screen;
	screen = create_back(path);
	while (!sfKeyboard_isKeyPressed(sfKeyReturn)) {
		sfRenderWindow_drawSprite
		(run->window, screen->my_back, NULL);
		sfRenderWindow_display(run->window);
	}
}

int stop(runer_t *run)
{
	int cpt = 0;

	if (run->perso->tabperso[0]->posperso.x
		> run->obj->mapblock[run->bleftmax]->posblock.x + 100) {
		fixscreen(run, "media/you_win.png");
		sfRenderWindow_close(run->window);
		return (1);
	}
	else if (run->perso->tabperso[0]->posperso.y >= 1000) {
		fixscreen(run, "media/you_lose.png");
		sfRenderWindow_close(run->window);
		return (1);
	}
	while (run->obj->mapblock[cpt] != NULL) {
		if (touchcollison(run, 2, cpt) == 1) {
			fixscreen(run, "media/you_lose.png");
			sfRenderWindow_close(run->window);
			return (1);
		}
		cpt++;
	}
	return (0);
}

void gameloop(runer_t *run)
{
	sfClock *clock = sfClock_create();
	sfTime time;
	float seconds = 0;

	fixscreen(run, "media/menu.png");
	while (sfRenderWindow_isOpen(run->window)) {
		if (stop(run) == 1)
			sfRenderWindow_close(run->window);
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000.0;
		while (sfRenderWindow_pollEvent(run->window, &run->event)) {
			if (run->event.type == sfEvtClosed)
				sfRenderWindow_close(run->window);
		}
		move_back(run->window, run->list);
		if (seconds > 0.08) {
			run->cpt_score++;
			move_perso(run->perso);
			sfClock_restart(clock);
		}
		perso_interaction(run);
		move_block(run->obj->mapblock, run->nbelem);
		display_all(run);
		sfRenderWindow_display(run->window);
	}
	sfRenderWindow_destroy(run->window);
}
