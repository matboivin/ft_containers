NAME = ft_containers
NAME_STD = original
NAME_CMP = test_containers

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .cpp .hpp .o

COL_WHITE_B = \033[1;37m
COL_RESET = \033[0m

# STL IMPLEMENTATION

IMPL_FILES = algorithm.hpp \
			 iterator.hpp \
			 type_traits.hpp \
			 vector.hpp

IMPL_DIR = ft_stl

# TESTS

TEST_INC_FILES = tests.hpp \
				 revit_tests.hpp \
				 vector_tests.hpp

TEST_SRC_FILES = main.cpp \
				 generate_output.cpp \
				 test_utils.cpp \
				 revit_test_comp_ops.cpp \
				 revit_test_construct.cpp \
				 revit_test_elem_access.cpp \
				 revit_test_inc_decr.cpp \
				 revit_test_math_ops.cpp \
				 revit_tests.cpp \
				 vector_test_capacity.cpp \
				 vector_test_construct.cpp \
				 vector_test_elements.cpp \
				 vector_test_iterator.cpp \
				 vector_test_modifiers.cpp \
				 vector_tests.cpp

INC_DIR = tests/include
SRC_DIR = tests/src
TEST_OUT_DIR = tests/outputs

SUBDIRS = vector iterator
SRC_SUBDIRS = $(addprefix $(SRC_DIR)/, $(SUBDIRS))

# OBJ

OBJ_FILES = $(TEST_SRC_FILES:%.cpp=%.o)
OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/ft/, $(OBJ_FILES))
OBJ_STD = $(addprefix $(OBJ_DIR)/original/, $(OBJ_FILES))
OBJ_CMP = $(OBJ_DIR)/cmp/main.o $(OBJ_DIR)/cmp/generate_output.o $(OBJ_DIR)/cmp/test_utils.o

# INC AND PATHS

INC = $(addprefix $(IMPL_DIR)/, $(IMPL_FILES)) \
	  $(addprefix $(INC_DIR)/, $(TEST_INC_FILES))

VPATH = $(SRC_DIR) $(SRC_SUBDIRS)

# COMPIL AND FLAGS

CPPFLAGS = -I$(IMPL_DIR) -I$(INC_DIR)
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# RULES

all: $(NAME) $(NAME_STD) $(NAME_CMP)

# OBJ DIR

$(OBJ_DIR):
	mkdir -p obj/ft obj/original obj/cmp

# TEST OUTPUTS DIR
$(TEST_OUT_DIR):
	mkdir -p $@

# COMPILING

$(OBJ_DIR)/cmp/%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR)/ft/%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -D TEST_FT -o $@ -c $<

$(OBJ_DIR)/original/%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -D TEST_STD -o $@ -c $<

# LINKING
$(NAME): $(TEST_OUT_DIR) $(OBJ_DIR) $(OBJ) $(INC)
	$(CXX) $(OBJ) -o $@
	@echo "$(COL_WHITE_B)$@ $(COL_RESET)created in working directory"

$(NAME_STD): $(TEST_OUT_DIR) $(OBJ_DIR) $(OBJ_STD) $(INC)
	$(CXX) $(OBJ_STD) -o $@
	@echo "$(COL_WHITE_B)$@ $(COL_RESET)created in working directory"

$(NAME_CMP): $(OBJ_DIR) $(OBJ_CMP)
	$(CXX) $(OBJ_CMP) -o $@
	@echo "$(COL_WHITE_B)$@ $(COL_RESET)created in working directory"

# DEBUG
debug:
	./$(NAME) > $(TEST_OUT_DIR)/mine.out 2>&1
	./$(NAME_STD) > $(TEST_OUT_DIR)/original.out 2>&1
	./$(NAME_CMP)

check_leaks: $(NAME)
	valgrind --leak-check=full ./$(NAME)

show:
	@echo "VPATH\n$(VPATH)\n"
	@echo "INC\n$(INC)\n"
	@echo "SRC_SUBDIRS\n$(SRC_SUBDIRS)"

# CLEAN

clean:
	$(RM) -rf $(OBJ_DIR) $(TEST_OUT_DIR)

fclean: clean
	$(RM) -f $(NAME) $(NAME_STD)

re: fclean all

.PHONY: all debug show clean fclean re
