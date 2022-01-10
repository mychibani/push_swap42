SRCS_FILES =		ft_parsing.c \
				ft_pushswap.c

#SRCS_BONUS_FILES =

OBJS_FILES =		${SRCS:.c=.o}

OBJ_BONUS	=		${SRCS_BONUS:.c=.o}

HEADER_FILES		=	-I$(HEADER_PATH)

HEADER_PATH		= 		.

HEADER_NAME		=	libft.h

SRCS_PATH =		.


CC		=	gcc

FLAGS		=	-Wall -Wextra -Werror

RM		=	rm -rf

HEADER		=	libft.h

NAME		=	libft.a

HEADER		=	$(addprefix $(HEADER_PATH)/, $(HEADER_NAME))

SRCS		=	$(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

SRCS_BONUS		=	$(addprefix $(SRCS_PATH)/, $(SRCS_BONUS_FILES))



all		:	$(NAME)


$(NAME)		:	$(OBJS_FILES) $(HEADER)
			ar rc $(NAME) $(OBJS_FILES)

%.o		:	%.c
			$(CC) $(FLAGS) $(HEADER_FILES) -c $< -o $@



bonus		:		$(OBJ_BONUS) $(OBJ) $(INC)
				ar rc $(NAME) $(OBJ_BONUS)
clean:
			${RM} ${OBJS_FILES} ${OBJ_BONUS}

fclean:		clean
			${RM} ${NAME}

re :		fclean all

.PHONY:		all clean fclean re
