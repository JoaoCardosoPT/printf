NAME = libftprintf.a

CC = cc
WFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c, ft_print_string.c, ft_pointer.c, ft_print_number.c,
ft_print_hex, ft_print_char.c, ft_format.c

HEADER = ft_printf.h

BSRC = $(SRCS:.c=.o)