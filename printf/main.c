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

	printf("=== All tests complete! ===\n");

	printf("%.03s\n", NULL);
	ft_printf("%.03s\n", NULL);
	printf("%3.1s\n", NULL);
	ft_printf("%3.1s\n", NULL);
	printf("%9.1s\n", NULL);
	ft_printf("%9.1s\n", NULL);
	printf("%-3.1s\n", NULL);
	ft_printf("%-3.1s\n", NULL);
	printf("%-9.1s\n", NULL);
	ft_printf("%-9.1s\n", NULL);
	printf("%.09s\n", NULL);
	ft_printf("%.09s\n", NULL);
	printf("%3.6s\n", NULL);
	ft_printf("%3.6s\n", NULL);
	printf("%20.6s\n", NULL);
	ft_printf("%20.6s\n", NULL);
	printf("%-3.8s\n", NULL);
	ft_printf("%-3.8s\n", NULL);
	printf("%-10.8s\n", NULL);
	ft_printf("%-10.8s\n", NULL);
	printf("%07i\n", -54);
	ft_printf("%07i\n", -54);
	printf("%04i\n", -532);
	ft_printf("%04i\n", -532);
	printf("%08.5i\n", 34);
	ft_printf("%08.5i\n", 34);
	printf("%010.5i\n", -216);
	ft_printf("%010.5i\n", -216);
	printf("%08.5i\n", 0);
	ft_printf("%08.5i\n", 0);
	printf("%08.3i\n", 8375);
	ft_printf("%08.3i\n", 8375);
	printf("%08.3i\n", -8473);
	ft_printf("%08.3i\n", -8473);
	printf("%.0i\n", 0);
	ft_printf("%.0i\n", 0);
	printf("%.i\n", 0);
	ft_printf("%.i\n", 0);
	printf("%5.0i\n", 0);
	ft_printf("%5.0i\n", 0);
	printf("%5.i\n", 0);
	ft_printf("%5.i\n", 0);
	printf("%-5.0i\n", 0);
	ft_printf("%-5.0i\n", 0);
	printf("%-5.i\n", 0);
	ft_printf("%-5.i\n", 0);
	printf("%07d\n", -54);
	ft_printf("%07d\n", -54);
	printf("%04d\n", -532);
	ft_printf("%04d\n", -532);

	printf("=== All tests complete! ===\n");
	return (0);
}
