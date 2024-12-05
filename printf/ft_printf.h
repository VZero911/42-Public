/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/05 03:40:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>

# define SPECIFIER	"cspdiuxX%"
# define FLAGS	"-0# +"
# define HEXA "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"
# define FLAG_LEFT_ALIGN    0x1
# define FLAG_ZERO_PADDING  0x2
# define FLAG_HASH          0x4
# define FLAG_SPACE         0x8
# define FLAG_PLUS          0x10
# define FLAG_PRECISION     0x20

typedef enum e_type
{
	SPECIFIER_CHAR		= 0,
	SPECIFIER_STRING		= 1,
	SPECIFIER_POINTER		= 2,
	SPECIFIER_INT		= 3,
	SPECIFIER_UNSIGNED		= 4,
	SPECIFIER_HEX_LOW		= 5,
	SPECIFIER_HEX_UP		= 6,
	SPECIFIER_PERCENTAGE		= 7,
	SPECIFIER_NONE		= -1
}	t_type;

typedef union u_var
{
	char			c;
	char			*s;
	void			*p;
	int				i;
	unsigned int	u;
	unsigned int	x;
}	t_var;

typedef struct s_data
{
	t_type	type;
	t_var	var;
	int		len;
	int		flags;
	int		width;
	int		precision;
}	t_struct;

typedef unsigned long long t_ull;

int		ft_printf(const char *str, ...);

int		ft_printf_parsing(const char *str, va_list *args);

void	ft_printf_char(t_struct *data);
void	ft_printf_string(t_struct *data);
void	ft_printf_percentage(t_struct *data);
void	ft_printf_pointer(t_struct *data);
void	ft_printf_int(t_struct *data);
void	ft_printf_uint(t_struct *data);
void	ft_printf_hex(t_struct *data, const char *base);

char	*apply_int_precision(char *nb_str, t_struct *data);
char	*ft_ulltoa_base(t_ull n, const char *base);
int		ft_putnbr_hex_low(unsigned int nb);
int		ft_putnbr_hex_up(unsigned int nb);

void	check_for_flags(char **current, t_struct *data);

void	ft_data_len(t_struct *data, int len);
void	apply_padding(char pad_char, int len);
void	print_and_pad(char *print_str, int padlen, char padding, t_struct *data);
char    padding_char(t_struct *data);

#endif
