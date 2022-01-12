SRCS_FILES		=	parsing.c			\
					push_swap.c			\
					operations.c		\
					main.c

HEADER_FILES	=	libft.h				\
					define.h			\
					fonctions.h			\
					includes.h


OBJS_FILES	=		${SRCS:.c=.o}

DEPENDS		=		$(SRCS:.c=.d)

HEADER_PATH	=		includes

HEADER_INC	=		-I $(HEADER_PATH)

SRCS_PATH 	=		srcs

CC			=		gcc

FLAGS		=		-Wall -Wextra -Werror

RM			=		rm -rf

NAME		=		push_swap

HEADER		=		$(addprefix $(HEADER_PATH)/, $(HEADER_FILES))

SRCS		=		$(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

_END=$'\x1b[0m'
_BOLD=$'\x1b[1m'
_UNDER=$'\x1b[4m'
_REV=$'\x1b[7m'

_GREY=$'\x1b[30m'
_RED=$'\x1b[31m'
_GREEN=$'\x1b[32m'
_YELLOW=$'\x1b[33m'
_BLUE=$'\x1b[34m'
_PURPLE=$'\x1b[35m'
_CYAN=$'\x1b[36m'
_WHITE=$'\x1b[37m'

_IGREY=$'\x1b[40m'
_IRED=$'\x1b[41m'
_IGREEN=$'\x1b[42m'
_IYELLOW=$'\x1b[43m'
_IBLUE=$'\x1b[44m'
_IPURPLE=$'\x1b[45m'
_ICYAN=$'\x1b[46m'
_IWHITE=$'\x1b[47m'

all		:	$(NAME)

%.o : %.c
		$(CC) -c $< -o $@ $(HEADER_INC)

$(NAME) : $(OBJS_FILES)
		$(CC) -o $@ $^

-include $(DEPENDS)

clean:
			$(RM) $(OBJS_FILES)

fclean:		clean
			$(RM) $(NAME)

re :		fclean all

.PHONY:		all clean fclean re
