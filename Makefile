BIN_NAME := ft_containers

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .cpp .hpp .o

# FILES

INC_FILES = iterator.hpp \
			vector.hpp \
			utils.hpp

INC_TEST_FILES = test_utils.hpp \
				 reverse_iterator_tests.hpp \
				 vector_tests.hpp

SRC_FILES = main.cpp \
			test_utils.cpp

SRC_FILES += vector_assignment_op.cpp \
			 vector_capacity.cpp \
			 vector_construct.cpp \
			 vector_tests.cpp

SRC_FILES += rev_it_advance.cpp \
			 rev_it_advdecr.cpp \
			 rev_it_assignment_op.cpp \
			 rev_it_decrease.cpp \
			 rev_it_relational_ops.cpp \
			 rev_it_tests.cpp

OBJ_FILES = $(SRC_FILES:%.cpp=%.o)

# DIRS AND PATHS

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SUB_DIRS = vector_tests reverse_iterator_tests
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

# COLORS

COL_WHITE_B = \033[1;37m
COL_RESET = \033[0m

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
	@echo "$(COL_WHITE_B)$@ $(COL_RESET)created in working directory"

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
