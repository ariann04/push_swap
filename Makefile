NAME = push_swap

SRCS = push_swap.c swap.c push.c rotate.c reverse.c algorithm.c minisort.c\
	   split_spaces.c check.c lst_utils.c error_handler.c bigsort.c\
	   calculate_cost.c calculate_index.c organize.c

OBJS = ${SRCS:.c=.o}

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

all: ${NAME}

${NAME}: ${OBJS} $(LIBFT)
				${CC} ${CFLAGS} ${OBJS} -L$(LIBFT_DIR) -lft -o ${NAME}

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	${REMOVE} ${OBJS} ${BONUS_OBJS}
	@make -sC $(LIBFT_DIR) clean

fclean:
	${REMOVE} ${OBJS}
	${REMOVE} ${NAME} ${PROGRAM}
	@make -sC $(LIBFT_DIR) fclean

.PHONY: all clean fclean
