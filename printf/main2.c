#include <stdio.h>
#include "ft_printf.h"

void	ft_test_flags(const char *format)
{
	t_struct	data;

	ft_memset(&data, 0, sizeof(t_struct));
	ft_get_data(&format, NULL, &data);

	printf("Remaining format: '%s'\n", format);
	printf("Flags: %d, Width: %d, Precision: %d\n", data.flags, data.width, data.precision);
}

int	main(void)
{
	ft_test_flags("%.3d");
	ft_test_flags("0#10x");
	ft_test_flags("+ 15c");
	ft_test_flags("5c");
	return (0);
}
