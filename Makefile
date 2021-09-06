BIN_NAME := ft_containers

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .cpp .hpp .o

INC_FILES = vector.hpp

SRC_FILES = main.cpp

OBJ_FILES = $(SRC_FILES:%.cpp=%.o)

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

INC = $(addprefix $(INC_DIR)/, $(INC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

VPATH = $(SRC_DIR)

CPPFLAGS = -I$(INC_DIR)
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(BIN_NAME)

# OBJ DIR

$(OBJ_DIR):
	mkdir -p $@

# COMPILING

$(OBJ_DIR)/%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

# LINKING

$(BIN_NAME): $(OBJ_DIR) $(OBJ) $(INC)
	$(CXX) $(OBJ) -o $@
	@echo "\nOK\t$@ is ready"

# DEBUG
debug: $(BIN_NAME)
	valgrind --leak-check=full ./$(BIN_NAME)

# CLEAN

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) -f $(BIN_NAME)

re: fclean all

.PHONY: all debug clean fclean re
