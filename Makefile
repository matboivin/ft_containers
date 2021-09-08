BIN_NAME := ft_containers

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .cpp .hpp .o

# FILES

INC_FILES = iterator.hpp \
			vector.hpp

INC_TEST_FILES = vector_tests.hpp

SRC_FILES = main.cpp \
			vector_assignment_op.cpp \
			vector_constructor.cpp \
			vector_tests.cpp

OBJ_FILES = $(SRC_FILES:%.cpp=%.o)

# DIRS AND PATHS

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SUB_DIRS = vector_tests
SRC_SUBDIRS = $(addprefix $(SRC_DIR)/, $(SUB_DIRS))

INC_SUBDIRS = $(addprefix $(INC_DIR)/, tests)

INC = $(addprefix $(INC_DIR)/, $(INC_FILES))
INC_TEST = $(addprefix $(INC_SUBDIRS)/, $(INC_TEST_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

VPATH = $(SRC_DIR) $(SRC_SUBDIRS)

# COMPIL AND FLAGS

CPPFLAGS = -I$(INC_DIR) -I$(INC_SUBDIRS)
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# RULES

all: $(BIN_NAME)

# OBJ DIR

$(OBJ_DIR):
	mkdir -p $@

# COMPILING

$(OBJ_DIR)/%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

# LINKING

$(BIN_NAME): $(OBJ_DIR) $(OBJ) $(INC) $(INC_TEST)
	$(CXX) $(OBJ) -o $@
	@echo "\nOK\t$@ is ready"

# DEBUG
debug: $(BIN_NAME)
	valgrind --leak-check=full ./$(BIN_NAME)

show:
	@echo "VPATH: $(VPATH)"
	@echo "SRC_SUBDIRS: $(SRC_SUBDIRS)"

# CLEAN

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) -f $(BIN_NAME)

re: fclean all

.PHONY: all debug clean fclean re
