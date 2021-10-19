NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

LIBFT	=	libft/ft_memchr.c		libft/ft_strlen.c		libft/ft_putcharlen_fd.c\
			libft/ft_strchr.c		libft/ft_strjoin.c		libft/ft_putstrlen_fd.c\
			libft/ft_itoa.c			libft/ft_atoi.c			libft/ft_strdup.c

SRC		=	src/ft_printf.c			src/ft_init.c			src/ft_typeofu.c\
			src/ft_args.c			src/ft_fillarray.c      src/ft_fillchr.c\
			src/ft_t_param.c          src/ft_fillstr.c		src/ft_widthzero.c\
			src/ft_widthminus.c		src/ft_prec.c			src/ft_numzero.c\
			src/ft_typeofx.c		src/ft_typeofcapx.c

HEADER	=	libft.h			ft_printf.h

OBJ		=	$(patsubst %.c,%.o,$(SRC))

LIBOBJ	=	$(patsubst %.c,%.o,$(LIBFT))

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBOBJ)
	ar rsc $(NAME) $?

%.o		: 	%.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	$(RM) $(OBJ) $(LIBOBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
