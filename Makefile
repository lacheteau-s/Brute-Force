SRC			=	src/main.c

OBJ			=	$(SRC:.c=.o)

NAME		=	pwdgen

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all