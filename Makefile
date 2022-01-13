SRCS_OPE		=	srcs/operations/operations.c

SRCS_SWAP		=	srcs/push_swap/push_swap.c		\
					srcs/push_swap/parsing.c		\
					srcs/push_swap/init.c

SRCS_CHECK		=	srcs/checker/checker.c

HEADER_FILES	=	libft.h							\
					define.h						\
					fonctions.h						\
					includes.h

CHECKER			=	checker

PUSH_SWAP 		= 	push_swap

OBJS_OPE 		= 	${SRCS_OPE:.c=.o}

OBJS_SWAP 		= 	${SRCS_SWAP:.c=.o}

OBJS_CHECK		=	${SRCS_CHECK:.c=.o}

INCS			=	-I ./includes -I libft/includes/

CC				=	clang

CFLAGS			=	-Wall -Wextra -Werror

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

all:		${PUSH_SWAP} ${CHECKER}

.c.o:
				@echo "Compiling ${_YELLOW}${_BOLD}$<${_END}..."
				@${CC} ${INCS} -c $< -o $@ ${INCS}

${PUSH_SWAP}:	${OBJS_SWAP} ${OBJS_OPE}
				@echo "Compiling ${_GREEN}${_BOLD}libft${_END}..."
				@${MAKE} -C libft >/dev/null
				@echo "Compiling ${_CYAN}${_BOLD}push_swap${_END}..."
				@${CC}  ${INCS} ${OBJS_SWAP} ${OBJS_OPE} -o ${PUSH_SWAP} libft/libft.a

${CHECKER}:		${OBJS_CHECK} ${OBJS_OPE}
				@echo "Compiling ${_GREEN}${_BOLD}libft${_END}..."
				@echo "Compiling ${_CYAN}${_BOLD}checker${_END}..."
				@${CC} ${INCS} ${OBJS_CHECK} ${OBJS_OPE} -o ${CHECKER} libft/libft.a

clean:
				@echo "Deleting ${_RED}${_BOLD}binary files${_END}..."
				@${RM} ${OBJS_SWAP} ${OBJS_CHECK} ${OBJS_OPE}
				@echo "Deleting ${_RED}${_BOLD}libft binary files${_END}..."
				@${MAKE} -C libft clean >/dev/null

fclean:			clean
				@echo "Deleting ${_RED}${_BOLD}push_swap and checker${_END}..."
				@${RM} ${OBJS_SWAP} ${OBJS_CHECK} ${OBJS_OPE} ${PUSH_SWAP} ${CHECKER}
				@echo "Deleting ${_RED}${_BOLD}libft librairy${_END}..."
				@${MAKE} -C libft fclean >/dev/null

re:				fclean all

.PHONY:			all clean fclean re
