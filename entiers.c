#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "include/chiffres.h"

char *get_string(char *prompt);
bool check_string(char *string);
bool check_strlen(char *string);
bool read(char *string, int n, bool exclude_zero);
void entier_to_text(char *entier);

char *units[] = {
	"mille",
	"million",
	"milliard"
};

int main()
{
	char character, *str_entier;
	int i = 0, j = 0;

	do {
		str_entier = get_string("Entrer un reele : ");
	} while (check_string(str_entier) || check_strlen(str_entier));
	entier_to_text(str_entier);
}

// convertir les chiffres au mots
void entier_to_text(char *entier)
{
	// afficher "moins" si le premier charactere est '-'
	if (entier[0] == '-')
	{
		printf("moins ");
		entier++;
	}

	int i = 0;
	int len = strlen(entier);
	int j = (len - 1)/ 3;
	while (i < len && j >= 0)
	{
        bool zero = read(entier + i, (len - i) % 3, i != 0);
		if (j != 0 && zero)
		{
			printf(" %s ", units[j]);
		}
        j--;
		i += (len - i) % 3 ? (len - i) % 3 : 3;
	}
	printf("\n");
}

// saisir une chaine de characters
char *get_string(char *prompt)
{
	printf("%s", prompt);
	char *chaine, character;
    int i = 0;
    chaine = (char *) malloc(sizeof(char));
    while ((character = getchar()) != '\n')
    {
        chaine[i++] = character;
        chaine = (char *) realloc(chaine, (i + 1) * sizeof(char));
    }
    chaine[i] = '\0';

    return chaine;
}

// verifer qu'une chaine de characters peut etre convertir a un reel
bool check_string(char *string)
{
	int i;
	if (string[0] == '-')
	{
		string++;
	}

	for (i = 0; i < strlen(string); i++)
	{
		if (string[i] > '9')
		{
			printf("Reel invalide\n");
			return true;
		}
	}
	return false;
}

// verifier que la taille de entier est inferieur a 13
bool check_strlen(char *string)
{
	if (strlen(string) > 12)
	{
		printf("la taille maximale est 12\n");
		return true;
	}
	return false;
}

// retourn si l'entier est un 0
bool read(char *string, int n, bool exclude_zero)
{
	n = n == 0 ? 3 : n;
	char buffer[3];
	int i;
	for (i = 0; i < n; i++)
	{
		buffer[i] = string[i];
	}
	buffer[i] = '\0';

	int entier = atoi(buffer);
	if (entier == 0 && exclude_zero)
	{
		return true;
	} else {
		printf("%s", nombres[entier]);
        return false;
	}
}
