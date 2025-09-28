NAME	:= philo
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -g
SRC_DIR = src
OBJ_DIR = obj

OBJS	:= ${SRCS:.c=.o}

SRCS	:= $(wildcard $(SRC_DIR)/*.c)
OBJS	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
