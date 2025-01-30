# Nom de l'exécutable principal
NAME = push_swap

# Nom de l'exécutable pour les tests
TEST_NAME = test_push_swap

# Fichiers sources et objets
SRC = src/main.c \
      src/instructions.c \
      src/instructions_2.c \
      src/instructions_3.c \
      src/stack_operations.c \
      src/sorting.c \
      src/error_handling.c\
	  src/tool.c\
	  src/tool_2.c\
	  src/tool_3.c

OBJ = $(SRC:.c=.o)

# Fichiers pour les tests
TEST_SRC = src/test.c
TEST_OBJ = $(TEST_SRC:.c=.o)

# Flags de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Libft (située à la racine)
LIBFT = libft.a

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable principal
$(NAME): $(OBJ) $(LIBFT)
	@echo "Compilation de $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "Compilation terminée."

# Compilation de libft
$(LIBFT):
	@echo "Compilation de la libft..."
	@$(MAKE) -C ./libft

# Compilation des fichiers objets principaux
%.o: %.c
	@echo "Compilation de $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation du fichier de test
$(TEST_NAME): $(OBJ) $(TEST_OBJ) $(LIBFT)
	@echo "Compilation des tests..."
	$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) $(LIBFT) -o $(TEST_NAME)
	@echo "Compilation des tests terminée."

# Règle de test : Compiler et exécuter les tests
test: $(TEST_NAME) clean
	@echo "Lancement des tests..."
	./$(TEST_NAME)

# Nettoyage des fichiers objets
clean:
	@echo "Nettoyage des fichiers objets..."
	rm -f $(OBJ) $(TEST_OBJ)

# Nettoyage complet (objets + exécutable principal + exécutable de tests)
fclean: clean
	@echo "Nettoyage complet..."
	rm -f $(NAME) $(TEST_NAME)

# Recompile tout
re: fclean all

# Déclaration des règles "phony"
.PHONY: all clean fclean re test
