SRCS_FILES =		ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isprint.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_striteri.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

SRCS_BONUS_FILES =	ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c

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

%o		:	%.c
			$(CC) $(FLAGS) $(HEADER_FILES) -c $< -o $@



bonus		:		$(OBJ_BONUS) $(OBJ) $(INC)
				ar rc $(NAME) $(OBJ_BONUS)
clean:
			${RM} ${OBJS_FILES} ${OBJ_BONUS}

fclean:		clean
			${RM} ${NAME}

re :		fclean all

.PHONY:		all clean fclean re
