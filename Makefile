SRCS_SWAP		=		srcs/push_swap/push_swap.c		\
					srcs/push_swap/parsing.c		\
					srcs/push_swap/init.c			\
					srcs/push_swap/tests_utils.c		\
					srcs/push_swap/cleaner_prog.c 		\


SRCS_OPE		=		srcs/operations/swap_ope.c		\
					srcs/operations/push_ope.c		\
					srcs/operations/reverse_rotate_ope.c	\
					srcs/operations/rotate_ope.c		\


SRCS_ALGO		=		srcs/algorithms/sorting.c		\
					srcs/algorithms/main_algo.c			\
					srcs/algorithms/sorting_utils.c		\
					srcs/algorithms/sorting_prep.c 

SRCS_UTILS		=		srcs/utils/ft_lstadd_back_data.c	\
					srcs/utils/ft_lstpush_front_data.c	\
					srcs/utils/ft_lstpush_back_data.c	\
					srcs/utils/ft_lstnew_doubly_linked.c	\

SRCS_CHECK		=		srcs/checker/checker.c


HEADER_FILES	=	libft.h							\
					define.h				\
					fonctions.h				\
					includes.h


CHECKER			=	checker

PUSH_SWAP 		= 	push_swap

OBJS_OPE 		= 	${SRCS_OPE:.c=.o}

OBJS_ALGO		=	${SRCS_ALGO:.c=.o}

OBJS_UTILS		=	${SRCS_UTILS:.c=.o}

OBJS_SWAP 		= 	${SRCS_SWAP:.c=.o}

OBJS_CHECK		=	${SRCS_CHECK:.c=.o}


INCS			=	-I ./includes -I libft/includes/

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address -g3

RM				=	rm -rf

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

all:		${PUSH_SWAP}

.c.o:
				@echo "Compiling ${_YELLOW}${_BOLD}$<${_END}..."
				@${CC} ${CFLAGS} ${INCS} -c $< -o $@ ${INCS}

${PUSH_SWAP}:	${OBJS_SWAP} ${OBJS_OPE} ${OBJS_ALGO} ${OBJS_UTILS}
				@echo "Compiling ${_GREEN}${_BOLD}libft${_END}..."
				@${MAKE} -C libft >/dev/null
				@echo "Compiling ${_CYAN}${_BOLD}push_swap${_END}..."
				@${CC} ${CFLAGS} ${INCS} ${OBJS_UTILS} ${OBJS_SWAP} ${OBJS_OPE} ${OBJS_ALGO} -o ${PUSH_SWAP} libft/libft.a

clean:
				@echo "Deleting ${_RED}${_BOLD}binary files${_END}..."
				@${RM} ${OBJS_SWAP} ${OBJS_CHECK} ${OBJS_OPE} ${OBJS_ALGO} ${OBJS_UTILS}
				@echo "Deleting ${_RED}${_BOLD}libft binary files${_END}..."
				@${MAKE} -C libft clean >/dev/null

fclean:			clean
				@echo "Deleting ${_RED}${_BOLD}push_swap and checker${_END}..."
				@${RM} ${OBJS_SWAP} ${OBJS_OPE} ${OBJS_ALGO} ${OBJS_UTILS} ${PUSH_SWAP}
				@echo "Deleting ${_RED}${_BOLD}libft librairy${_END}..."
				@${MAKE} -C libft fclean >/dev/null

re:				fclean all

.PHONY:			all clean fclean re
