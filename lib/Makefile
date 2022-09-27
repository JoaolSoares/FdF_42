NAME = libft.a

GREEN				= \033[1;32m
NOCOLOR				= \033[0m

SRCS =  ./srcs/ft_atoi.c \
        ./srcs/ft_bzero.c \
        ./srcs/ft_calloc.c \
        ./srcs/ft_isalnum.c \
        ./srcs/ft_isalpha.c \
        ./srcs/ft_isascii.c \
        ./srcs/ft_isdigit.c \
        ./srcs/ft_isprint.c \
    	./srcs/ft_memchr.c \
        ./srcs/ft_memcmp.c \
        ./srcs/ft_memcpy.c \
        ./srcs/ft_memmove.c \
        ./srcs/ft_memset.c \
        ./srcs/ft_strchr.c \
        ./srcs/ft_strdup.c \
        ./srcs/ft_strlcat.c \
        ./srcs/ft_strlcpy.c \
        ./srcs/ft_strlen.c \
        ./srcs/ft_strncmp.c \
        ./srcs/ft_strnstr.c \
        ./srcs/ft_strrchr.c \
        ./srcs/ft_tolower.c \
		./srcs/ft_toupper.c \
		./srcs/ft_substr.c \
		./srcs/ft_strjoin.c \
		./srcs/ft_strtrim.c \
		./srcs/ft_split.c \
		./srcs/ft_itoa.c \
		./srcs/ft_strmapi.c \
		./srcs/ft_striteri.c \
		./srcs/ft_putchar_fd.c \
		./srcs/ft_putstr_fd.c \
		./srcs/ft_putendl_fd.c \
		./srcs/ft_putnbr_fd.c \
		./srcs/ft_strlen_until.c \
		./srcs/get_next_line.c \
		./srcs/ft_printf_lib/ft_printf.c \
		./srcs/ft_printf_lib/conversions.c \
		./srcs/ft_printf_lib/hexptrcase.c \
		./srcs/ft_printf_lib/utils.c

OBJS = ${SRCS:.c=.o}

INCS = -I ./include

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	@ cc ${CFLAGS} ${INCS} -c $< -o $@

${NAME}: ${OBJS}
	@ ar -rcs ${NAME} ${OBJS}
	@ echo "${GREEN}-=- LIBFT SUCCESSFUL COMPILED -=-${NOCOLOR}"

clean:	
	@ rm -f ${OBJS}
	@ echo "${GREEN}-=- CLEANED -=-${NOCOLOR}"

fclean: clean
	@ rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re