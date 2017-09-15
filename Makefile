NAME		=	pwdgen

SRC			=	src/tools/output.c	\
				src/tools/strings.c	\
				src/tools/utils.c	\
				src/opts.c			\
				src/main.c

OBJ			=	$(SRC:.c=.o)

INCLUDES	=	-I ./headers

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all