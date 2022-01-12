SRCS_FILES		=	parsing.c			\
					push_swap.c			\
					operations.c		\
					push_swap/main.c

HEADER_FILES	=	libft.h				\
					define.h			\
					fonctions.h			\
					includes.h


OBJS_FILES	=		${SRCS:.c=.o}

DEPENDS		=		$(SRCS:.c=.d)

HEADER_PATH	=		includes

HEADER_INC	=		-I $(HEADER_PATH)

SRCS_PATH 	=		srcs/push_swap	\
					srcs/checker 	\
					srcs/operations

CC			=		gcc

FLAGS		=		-Wall -Wextra -Werror

RM			=		rm -rf

NAME		=		push_swap

HEADER		=		$(addprefix $(HEADER_PATH)/, $(HEADER_FILES))

SRCS		=		$(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

_END=$'\e[0m
_BOLD=$'\e[1m
_UNDER=$'\e[4m
_REV=$'\e[7m

_GREY=$'\e[30m
_RED=$'\e[0;31m
_GREEN=$'\e[32m
_YELLOW=$'\e[33m
_BLUE=$'\e[34m
_PURPLE=$'\e[35m
_CYAN=$'\e[36m
_WHITE=$'\e[37m

_IGREY=$'\e[40m
_IRED=$'\e[41m
_IGREEN=$'\e[42m
_IYELLOW=$'\e[43m
_IBLUE=$'\e[44m
_IPURPLE=$'\e[45m
_ICYAN=$'\e[46m
_IWHITE=$'\e[47m

all		:	$(NAME)

echo	:
		@echo $(SRCS)
# %.o : %.c
# 		@$(CC) $(FLAGS) -c $< -o $@ $(HEADER_INC)

# $(NAME) : $(OBJS_FILES)
# 		@$(CC) -o $@ $^
# 		@ echo "${_GREEN}push_swap.exe is done${_END}"

# -include $(DEPENDS)

# clean:
# 			@$(RM) $(OBJS_FILES)
# 			@ echo "${_RED}objects files Removed${_END}"

# fclean:		clean
# 			@$(RM) $(NAME)
# 			@ echo "${_RED}push_swap.exe Removed${_END}"

# re :		fclean all

# .PHONY:		all clean fclean re
