NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
INCLUDE = ./libft/libft.a

SRCS = aux.c descriptors.c parse.c pipes.c process.c special_split.c
MAIN = main.c
BMAIN = bonus.c

ifeq ($(MAKECMDGOALS), bonus)
	SRCS += $(BMAIN)
	RM_EXTRA = rm -f $(MAIN:.c=.o)
else
	SRCS += $(MAIN)
	RM_EXTRA = rm -f $(BMAIN:.c=.o)
endif

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $(<) -o $(@)

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C $(LIBFT_DIR)
	@$(RM_EXTRA)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

bonus: $(NAME)

clean:
	@make -s -C $(LIBFT_DIR) clean 
	@rm -rf $(OBJS)
	@rm -f bonus.o

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean 
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re