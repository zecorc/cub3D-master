NAME		= cub3D

SRCS_LIST	= 	main.c \
				iwu.c \
				gam3.c \
				imputss.c \
				get_next_line.c \
				get_next_line_utils.c \
				parse.c \
				parse_utils.c \
				parse_set1.c \
				parse_set2.c \
				parse_utils_2.c \
				atoi.c

SRCS		= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS		= ${SRCS:.c=.o}

HEADER		= includes
FOLDER		= files
MLX			= minilibx
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
LFLAGS		= -lmlx -framework OpenGL -framework AppKit -lm
RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) $(CFLAGS) $(LFLAGS) -I $(HEADER) $(OBJS) -o $(NAME)

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM)	$(NAME)
		
re:		fclean all