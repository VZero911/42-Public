#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	// Variables pour tester
	int		i = 42;
	char	c = 'A';
	char	*str = "Hello, world!";
	int		neg = -12345;
	unsigned int u = 12345;
	unsigned int hex = 0xdeadbeef;
	double	flt = 3.14159;

	// Test simple
	printf("\n\n\t=== Simple String Test ===\n\n");
	printf("Native:   |Hello, world!|\n");
	ft_printf("Custom:   |Hello, world!|\n");
	printf("\n");

	// Test d'un caractère
	printf("\n\t=== Character Test ===\n\n");
	printf("Native:   |%c|\n", c);
	ft_printf("Custom:   |%c|\n", c);
	printf("Native:   |%5c|\n", c);
	ft_printf("Custom:   |%5c|\n", c);
	printf("\n");

	printf("\n\t=== Character Test Complete ===\n");
	// Test d'une chaîne
	printf("\n\n\t=== String Test ===\n\n");
	// Cas basiques pour l'affichage de chaînes
	printf("Native:   |%s|\n", str);
	ft_printf("Custom:   |%s|\n", str);
	// Cas avec largeur, aligné à droite (décalage à droite)
	printf("Native:   |%20s|\n", str);
	ft_printf("Custom:   |%20s|\n", str);
	// Cas avec largeur, aligné à gauche
	printf("Native:   |%-20s|\n", str);
	ft_printf("Custom:   |%-20s|\n", str);
	// Cas avec précision (limiter le nombre de caractères affichés)
	printf("Native:   |%.5s|\n", str);
	ft_printf("Custom:   |%.5s|\n", str);
	// Cas avec NULL pour vérifier le comportement quand la chaîne est NULL
	printf("Native:   |%.03s|\n", NULL);
	ft_printf("Custom:   |%.03s|\n", NULL);
	printf("Native:   |%3.1s|\n", NULL);
	ft_printf("Custom:   |%3.1s|\n", NULL);
	printf("Native:   |%9.1s|\n", NULL);
	ft_printf("Custom:   |%9.1s|\n", NULL);
	printf("Native:   |%-3.1s|\n", NULL);
	ft_printf("Custom:   |%-3.1s|\n", NULL);
	printf("Native:   |%-9.1s|\n", NULL);
	ft_printf("Custom:   |%-9.1s|\n", NULL);
	// Cas avec des chaînes NULL et largeur et précision spécifiques
	printf("Native:   |%.09s|\n", NULL);
	ft_printf("Custom:   |%.09s|\n", NULL);
	printf("Native:   |%3.6s|\n", NULL);
	ft_printf("Custom:   |%3.6s|\n", NULL);
	printf("Native:   |%20.6s|\n", NULL);
	ft_printf("Custom:   |%20.6s|\n", NULL);
	// Cas avec des chaînes NULL et largeur et précision spécifiques en alignement à gauche
	printf("Native:   |%-3.8s|\n", NULL);
	ft_printf("Custom:   |%-3.8s|\n", NULL);
	printf("Native:   |%-10.8s|\n", NULL);
	ft_printf("Custom:   |%-10.8s|\n", NULL);

	printf("\n\t=== String Test Complete ===\n");


		// Test d'un entier
	printf("\n\n\t=== Integer Tests ===\n\n");
	// Cas avec -54
	printf("Native:   |%d|\n", INT_MIN);
	ft_printf("Custom:   |%d|\n", INT_MIN);
	printf("Native:   |%07d|\n", -54);
	ft_printf("Custom:   |%07d|\n", -54);
	printf("Native:   |%04d|\n", -532);
	ft_printf("Custom:   |%04d|\n", -532);
	// Cas avec précision et largeur
	printf("Native:   |%08.5i|\n", 34);
	ft_printf("Custom:   |%08.5i|\n", 34);
	printf("Native:   |%010.5i|\n", -216);
	ft_printf("Custom:   |%010.5i|\n", -216);
	// Cas spécial avec 0
	printf("Native:   |%08.5i|\n", 0);
	ft_printf("Custom:   |%08.5i|\n", 0);
	printf("Native:   |%08.3i|\n", 8375);
	ft_printf("Custom:   |%08.3i|\n", 8375);
	printf("Native:   |%08.3i|\n", -8473);
	ft_printf("Custom:   |%08.3i|\n", -8473);
	// Cas précision 0
	printf("Native:   |%.0i|\n", 0);
	ft_printf("Custom:   |%.0i|\n", 0);
	printf("Native:   |%.i|\n", 0);
	ft_printf("Custom:   |%.i|\n", 0);
	// Cas précision et largeur
	printf("Native:   |%5.0i|\n", 0);
	ft_printf("Custom:   |%5.0i|\n", 0);
	printf("Native:   |%5.i|\n", 0);
	ft_printf("Custom:   |%5.i|\n", 0);
	// Cas alignement gauche
	printf("Native:   |%-5.0i|\n", 0);
	ft_printf("Custom:   |%-5.0i|\n", 0);
	printf("Native:   |%-5.i|\n", 0);
	ft_printf("Custom:   |%-5.i|\n", 0);
	// Cas avec -54 et padding
	printf("Native:   |%07d|\n", -54);
	ft_printf("Custom:   |%07d|\n", -54);
	printf("Native:   |%04d|\n", -532);
	ft_printf("Custom:   |%04d|\n", -532);

	printf("\n\t=== Integer Tests Complete ===\n");


	// Test d'un entier non signé
		printf("\n\n\t=== Unsigned Integer Test ===\n\n");
	// Cas de base avec l'affichage d'un entier non signé
	printf("Native:   |%u|\n", u);
	ft_printf("Custom:   |%u|\n", u);
	printf("Native:   |%05u|\n", u);
	ft_printf("Custom:   |%05u|\n", u);
	printf("Native:   |%10u|\n", u);
	ft_printf("Custom:   |%10u|\n", u);
	// Cas divers pour les entiers non signés avec différentes largeurs et précisions
	printf("Native:   |%7u|\n", 33);
	ft_printf("Custom:   |%7u|\n", 33);
	printf("Native:   |%3u|\n", 0);
	ft_printf("Custom:   |%3u|\n", 0);
	printf("Native:   |%-7u|\n", 33);
	ft_printf("Custom:   |%-7u|\n", 33);
	printf("Native:   |%-3u|\n", 0);
	ft_printf("Custom:   |%-3u|\n", 0);
	printf("Native:   |%.5u|\n", 2);
	ft_printf("Custom:   |%.5u|\n", 2);
	printf("Native:   |%.3u|\n", 0);
	ft_printf("Custom:   |%.3u|\n", 0);
	printf("Native:   |%05u|\n", 43);
	ft_printf("Custom:   |%05u|\n", 43);
	printf("Native:   |%03u|\n", 0);
	ft_printf("Custom:   |%03u|\n", 0);
	printf("Native:   |%8.5u|\n", 34);
	ft_printf("Custom:   |%8.5u|\n", 34);
	printf("Native:   |%8.5u|\n", 0);
	ft_printf("Custom:   |%8.5u|\n", 0);
	printf("Native:   |%8.3u|\n", 8375);
	ft_printf("Custom:   |%8.3u|\n", 8375);
	printf("Native:   |%3.7u|\n", 3267);
	ft_printf("Custom:   |%3.7u|\n", 3267);
	printf("Native:   |%-8.5u|\n", 34);
	ft_printf("Custom:   |%-8.5u|\n", 34);
	printf("Native:   |%-8.5u|\n", 0);
	ft_printf("Custom:   |%-8.5u|\n", 0);
	printf("Native:   |%-8.3u|\n", 8375);
	ft_printf("Custom:   |%-8.3u|\n", 8375);
	printf("Native:   |%-3.7u|\n", 3267);
	ft_printf("Custom:   |%-3.7u|\n", 3267);
	printf("Native:   |%08.5u|\n", 34);
	ft_printf("Custom:   |%08.5u|\n", 34);
	printf("Native:   |%08.5u|\n", 0);
	ft_printf("Custom:   |%08.5u|\n", 0);
	printf("Native:   |%08.3u|\n", 8375);
	ft_printf("Custom:   |%08.3u|\n", 8375);
	printf("Native:   |%03.7u|\n", 3267);
	ft_printf("Custom:   |%03.7u|\n", 3267);
	printf("Native:   |%u|\n", 4294967295u);
	ft_printf("Custom:   |%u|\n", 4294967295u);
	printf("\n\t=== Unsigned Integer Test Complete ===\n\n");


	// Test d'un entier hexadécimal
	printf("\n\n\t=== Hexadecimal Test ===\n\n");
	printf("Native:   |%x|\n", hex);
	ft_printf("Custom:   |%x|\n", hex);
	printf("Native:   |%X|\n", hex);
	ft_printf("Custom:   |%X|\n", hex);
	printf("Native:   |%#x|\n", hex);
	ft_printf("Custom:   |%#x|\n", hex);
	printf("Native:   |%#X|\n", hex);
	ft_printf("Custom:   |%#X|\n", hex);
	printf("Native:   |%.5x|\n", 21);
	ft_printf("Custom:   |%.5x|\n", 21);
	printf("Native:   |%.3x|\n", 0);
	ft_printf("Custom:   |%.3x|\n", 0);
	printf("Native:   |%8.5x|\n", 34);
	ft_printf("Custom:   |%8.5x|\n", 34);
	printf("Native:   |%8.5x|\n", 0);
	ft_printf("Custom:   |%8.5x|\n", 0);
	printf("Native:   |%2.7x|\n", 3267);
	ft_printf("Custom:   |%2.7x|\n", 3267);
	printf("Native:   |%-8.5x|\n", 34);
	ft_printf("Custom:   |%-8.5x|\n", 34);
	printf("Native:   |%-8.5x|\n", 0);
	ft_printf("Custom:   |%-8.5x|\n", 0);
	printf("Native:   |%-2.7x|\n", 3267);
	ft_printf("Custom:   |%-2.7x|\n", 3267);
	printf("Native:   |%08.5x|\n", 34);
	ft_printf("Custom:   |%08.5x|\n", 34);
	printf("Native:   |%08.5x|\n", 0);
	ft_printf("Custom:   |%08.5x|\n", 0);
	printf("Native:   |%02.7x|\n", 3267);
	ft_printf("Custom:   |%02.7x|\n", 3267);
	printf("Native:   |%.0x|\n", 0);
	ft_printf("Custom:   |%.0x|\n", 0);
	printf("Native:   |%.x|\n", 0);
	ft_printf("Custom:   |%.x|\n", 0);
	printf("Native:   |%5.0x|\n", 0);
	ft_printf("Custom:   |%5.0x|\n", 0);
	printf("Native:   |%5.x|\n", 0);
	ft_printf("Custom:   |%5.x|\n", 0);
	printf("Native:   |%-5.0x|\n", 0);
	ft_printf("Custom:   |%-5.0x|\n", 0);
	printf("Native:   |%-5.x|\n", 0);
	ft_printf("Custom:   |%-5.x|\n", 0);
	printf("Native:   |%.5x|\n", 21);
	ft_printf("Custom:   |%.5x|\n", 21);
	printf("Native:   |%.3x|\n", 0);
	ft_printf("Custom:   |%.3x|\n", 0);
	printf("Native:   |%8.5x|\n", 34);
	ft_printf("Custom:   |%8.5x|\n", 34);
	printf("\n");
	printf("\n\t=== Hexadecimal Test Complete ===\n\n");

	// Test de précision
	printf("\n\n\t=== Precision Test ===\n\n");
	printf("Native:   |%.5d|\n", i);
	ft_printf("Custom:   |%.5d|\n", i);
	printf("Native:   |%.5u|\n", u);
	ft_printf("Custom:   |%.5u|\n", u);
	printf("Native:   |%.5x|\n", hex);
	ft_printf("Custom:   |%.5x|\n", hex);
	printf("\n");

	// Test de combinaisons de flags
	printf("\n\n\t=== Flag Combination Test ===\n\n");
	printf("Native:   |%-05d|\n", i);
	ft_printf("Custom:   |%-05d|\n", i);
	printf("Native:   |%+10.5d|\n", i);
	ft_printf("Custom:   |%+10.5d|\n", i);
	printf("Native:   |%+ d|\n", i);
	ft_printf("Custom:   |%+ d|\n", i);
	printf("Native:   |%0#10x|\n", hex);
	ft_printf("Custom:   |%0#10x|\n", hex);
	printf("\n");

	// Test de pourcentage
	printf("\n\n\t=== Percent Test ===\n\n");
	printf("Native:   |%%|\n");
	ft_printf("Custom:   |%%|\n");
	printf("\n");

	// Test de flottants (si implémenté)
	printf("\n\n\t=== Float Test (if implemented) ===\n\n");
	printf("Native:   |%f|\n", flt);
	ft_printf("Custom:   |%f|\n", flt);
	printf("Native:   |%.2f|\n", flt);
	ft_printf("Custom:   |%.2f|\n", flt);
	printf("Native:   |%10.2f|\n", flt);
	ft_printf("Custom:   |%10.2f|\n", flt);
	printf("\n");


	printf("\n=== All tests complete! ===\n");

	return (0);
}
