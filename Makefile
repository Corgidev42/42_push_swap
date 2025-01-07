# Nom de l'exécutable
NAME = push_swap

# Fichiers sources et objets
SRC = src/main.c \
      src/instructions.c \
	  src/instructions_2.c \
	  src/instructions_3.c \
      src/stack_operations.c \
      src/sorting.c \
      src/error_handling.c

OBJ = $(SRC:.c=.o)

# Flags de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Libft (située à la racine)
LIBFT = libft.a

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJ) $(LIBFT)
	@echo "Compilation de $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "Compilation terminée."

# Compilation de libft
$(LIBFT):
	@echo "Compilation de la libft..."
	@$(MAKE) -C ./libft

# Compilation des fichiers objets
%.o: %.c
	@echo "Compilation de $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@echo "Nettoyage des fichiers objets..."
	rm -f $(OBJ)

# Nettoyage complet (objets + exécutable)
fclean: clean
	@echo "Nettoyage complet..."
	rm -f $(NAME)

# Recompile tout
re: fclean all

# Déclaration des règles "phony"
.PHONY: all clean fclean re
