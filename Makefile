# Paths
LIBFT_PATH    := include/libft

# Compiler + flags
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -I include 

# Libraries
LIBFT_LIB := $(LIBFT_PATH)/libft.a

# Source & objects
SRC     := $(wildcard src/*.c)
OBJDIR  := obj
OBJ     := $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRC))

NAME  := push_swap

# Main target
all: $(LIBFT_LIB) $(NAME)

# Build libft
$(LIBFT_LIB):
	@$(MAKE) -s -C $(LIBFT_PATH)

# Link push_swap
$(NAME): $(OBJ) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(OBJ) \
	      -L$(LIBFT_PATH) -lft\
	      -o $(NAME)

# Compile .c → .o
$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Ensure obj dir
$(OBJDIR):
	mkdir -p $(OBJDIR)

VG_FLAGS  := --leak-check=full \
             --show-leak-kinds=all \
             --track-origins=yes \
             --error-exitcode=1

valgrind: all
	@$(MAKE) CFLAGS="$(CFLAGS) -g" all

# Clean rules
clean:
	-$(MAKE) -C $(LIBFT_PATH) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

# san: CFLAGS += -fsanitize=address -fno-omit-frame-pointer -g
san: CFLAGS += -fsanitize=address -g -static-libsan  -Wunused
san: fclean all

.PHONY: all clean fclean re