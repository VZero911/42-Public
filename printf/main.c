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
	printf("=== Simple String Test ===\n");
	printf("Native:   |Hello, world!|\n");
	ft_printf("Custom:   |Hello, world!|\n");
	printf("\n");

	// Test d'un caractère
	printf("=== Character Test ===\n");
	printf("Native:   |%c|\n", c);
	ft_printf("Custom:   |%c|\n", c);
	printf("Native:   |%5c|\n", c);
	ft_printf("Custom:   |%5c|\n", c);
	printf("\n");

	// Test d'une chaîne
	printf("=== String Test ===\n");
	printf("Native:   |%s|\n", str);
	ft_printf("Custom:   |%s|\n", str);
	printf("Native:   |%20s|\n", str);
	ft_printf("Custom:   |%20s|\n", str);
	printf("Native:   |%-20s|\n", str);
	ft_printf("Custom:   |%-20s|\n", str);
	printf("Native:   |%.5s|\n", str);
	ft_printf("Custom:   |%.5s|\n", str);
	printf("\n");

	// Test d'un entier
	printf("=== Integer Test ===\n");
	printf("Native:   |%d|\n", i);
	ft_printf("Custom:   |%d|\n", i);
	printf("Native:   |%05d|\n", i);
	ft_printf("Custom:   |%05d|\n", i);
	printf("Native:   |%-5d|\n", i);
	ft_printf("Custom:   |%-5d|\n", i);
	printf("Native:   |%+d|\n", i);
	ft_printf("Custom:   |%+d|\n", i);
	printf("Native:   |% d|\n", i);
	ft_printf("Custom:   |% d|\n", i);
	printf("Native:   |%d|\n", neg);
	ft_printf("Custom:   |%d|\n", neg);
	printf("\n");

	// Test d'un entier non signé
	printf("=== Unsigned Integer Test ===\n");
	printf("Native:   |%u|\n", u);
	ft_printf("Custom:   |%u|\n", u);
	printf("Native:   |%05u|\n", u);
	ft_printf("Custom:   |%05u|\n", u);
	printf("Native:   |%10u|\n", u);
	ft_printf("Custom:   |%10u|\n", u);
	printf("\n");

	// Test d'un entier hexadécimal
	printf("=== Hexadecimal Test ===\n");
	printf("Native:   |%x|\n", hex);
	ft_printf("Custom:   |%x|\n", hex);
	printf("Native:   |%X|\n", hex);
	ft_printf("Custom:   |%X|\n", hex);
	printf("Native:   |%#x|\n", hex);
	ft_printf("Custom:   |%#x|\n", hex);
	printf("Native:   |%#X|\n", hex);
	ft_printf("Custom:   |%#X|\n", hex);
	printf("\n");

	// Test de précision
	printf("=== Precision Test ===\n");
	printf("Native:   |%.5d|\n", i);
	ft_printf("Custom:   |%.5d|\n", i);
	printf("Native:   |%.5u|\n", u);
	ft_printf("Custom:   |%.5u|\n", u);
	printf("Native:   |%.5x|\n", hex);
	ft_printf("Custom:   |%.5x|\n", hex);
	printf("\n");

	// Test de combinaisons de flags
	printf("=== Flag Combination Test ===\n");
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
	printf("=== Percent Test ===\n");
	printf("Native:   |%%|\n");
	ft_printf("Custom:   |%%|\n");
	printf("\n");

	// Test de flottants (si implémenté)
	printf("=== Float Test (if implemented) ===\n");
	printf("Native:   |%f|\n", flt);
	ft_printf("Custom:   |%f|\n", flt);
	printf("Native:   |%.2f|\n", flt);
	ft_printf("Custom:   |%.2f|\n", flt);
	printf("Native:   |%10.2f|\n", flt);
	ft_printf("Custom:   |%10.2f|\n", flt);
	printf("\n");

	// Fin
	printf("=== All tests complete! ===\n");
	return (0);
}
