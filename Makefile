NAME := ft_containers

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .cpp .hpp .o

# STL IMPLEMENTATION

IMPL_FILES = algorithm.hpp \
			 iterator.hpp \
			 type_traits.hpp \
			 vector.hpp \
			 utils.hpp

# TESTS

TEST_INC_FILES = tests.hpp \
				 vector_tests.hpp

TEST_SRC_FILES = main.cpp

# OBJ

OBJ_FILES = $(TEST_SRC_FILES:%.cpp=%.o)

# DIRS AND PATHS

IMPL_DIR = ft_stl
INC_DIR = tests/include
SRC_DIR = tests/src
OBJ_DIR = obj

SUB_DIRS = vector
SRC_SUBDIRS = $(addprefix $(SRC_DIR)/, $(SUB_DIRS))

INC = $(addprefix $(IMPL_DIR)/, $(IMPL_FILES)) $(addprefix $(INC_DIR)/, $(TEST_INC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

VPATH = $(SRC_DIR) $(SRC_SUBDIRS)

# COMPIL AND FLAGS

CPPFLAGS = -I$(IMPL_DIR) -I$(INC_DIR)
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# COLORS

COL_WHITE_B = \033[1;37m
COL_RESET = \033[0m

# RULES

all: $(NAME)

# OBJ DIR

$(OBJ_DIR):
	mkdir -p $@

# COMPILING

$(OBJ_DIR)/%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

# LINKING

$(NAME): $(OBJ_DIR) $(OBJ) $(INC)
	$(CXX) $(OBJ) -o $@
	@echo "$(COL_WHITE_B)$@ $(COL_RESET)created in working directory"

# DEBUG
debug: $(NAME)
	valgrind --leak-check=full ./$(NAME)

show:
	@echo "VPATH\n$(VPATH)\n"
	@echo "INC\n$(INC)\n"
	@echo "SRC_SUBDIRS\n$(SRC_SUBDIRS)"

# CLEAN

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all debug show clean fclean re
