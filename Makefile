# Compiler et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Nom du projet
PROJECT_NAME = push_swap

# Include path (répertoire contenant les fichiers headers du projet)
INCLUDES = -Iinclude

# Library path for libft.a (chemin vers libft.a)
LIBFT_DIR = mylib
LIBFT = $(LIBFT_DIR)/lib/libft.a

# Répertoire source du projet
SRC_DIR = src

# Trouver tous les fichiers .c dans le répertoire src/
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Répertoire où seront stockés les fichiers objets
OBJ_DIR = obj

# Liste des fichiers objets (transformation des .c en .o dans obj/)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Default target : compile le projet principal
all: $(PROJECT_NAME)

$(PROJECT_NAME): $(LIBFT) $(OBJ_FILES)
	@make -C $(LIBFT_DIR)
	@echo "Linking $(PROJECT_NAME)..."
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_FILES) -o $@ $(LIBFT)

# Règle pour compiler les fichiers sources .c en fichiers objets .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

# Création du répertoire obj s'il n'existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

# Nettoyage des fichiers objets uniquement
clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "Cleaned object files."

# Nettoyage complet : objets, exécutable principal et fichiers de test
fclean: clean
	@rm -f $(PROJECT_NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "Fully cleaned: removed executables and test binaries."

# Reconstruire tout (objets, exécutable principal, puis tests)
re: fclean all
	@echo "Rebuilt everything."