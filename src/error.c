/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** error
*/

#include "struct.h"
#include "my.h"

int errormap(runer_t *run)
{
	int cpt = 0;

	while (run->map[cpt] != '\0') {
		if ((run->map[cpt] != '.' && run->map[cpt] != '1') &&
			(run->map[cpt] != '2' && run->map[cpt] != '\n'))
			return (84);
		cpt++;
	}
	return (0);
}

int error (int argc, char **argv)
{
	int cpt = 0;
	int ok = 0;

	if (argc != 2) {
		my_putstr("\t\texecute ./my_runner -h\n");
		return (84);
	}
	else if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
		usage();
		return (84);
	}
	while (argv[1][cpt] != '\0') {
		if ((argv[1][cpt] == '.' && argv[1][cpt + 1] == 't') &&
			(argv[1][cpt + 2] == 'x' && argv[1][cpt + 3] == 't'))
			ok = 1;
		cpt++;
	}
	if (ok == 0)
		return (84);
	return (0);
}
