NAME =		ft_containers
NAME_STD =	original
NAME_CMP =	test_containers

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .cpp .hpp .o

COL_WHITE_B =	\033[1;37m
COL_RESET =		\033[0m

# STL IMPLEMENTATION

IMPL_FILES =		algorithm.hpp \
					iterator.hpp \
					map.hpp \
					set.hpp \
					stack.hpp \
					tree.hpp \
					type_traits.hpp \
					utility.hpp \
					vector.hpp

# TEST FILES

INC_FILES =			tests.hpp \
					map_tests.hpp \
					revit_tests.hpp \
					set_tests.hpp \
					stack_tests.hpp \
					vector_tests.hpp

CMP_SRC_FILES =		main.cpp \
					generate_output.cpp \
					test_utils.cpp

IT_SRC_FILES =		revit_test_comp_ops.cpp \
					revit_test_construct.cpp \
					revit_test_elem_access.cpp \
					revit_test_inc_decr.cpp \
					revit_test_math_ops.cpp \
					revit_tests.cpp

MAP_SRC_FILES =		map_tests_capacity.cpp \
					map_tests_comp_ops.cpp \
					map_tests_construct.cpp \
					map_tests_elements.cpp \
					map_tests_iterators.cpp \
					map_tests_lookup.cpp \
					map_tests_modifiers.cpp \
					map_tests_observers.cpp \
					map_tests_swap.cpp \
					map_tests.cpp

SET_SRC_FILES =		set_test_construct.cpp \
					set_tests_capacity.cpp \
					set_tests_comp_ops.cpp \
					set_tests_iterators.cpp \
					set_tests_lookup.cpp \
					set_tests_modifiers.cpp \
					set_tests_observers.cpp \
					set_tests_swap.cpp \
					set_tests.cpp

STACK_SRC_FILES =	stack_test_capacity.cpp \
					stack_test_comp_ops.cpp \
					stack_test_construct.cpp \
					stack_test_elements.cpp \
					stack_test_modifiers.cpp \
					stack_tests.cpp

TREE_SRC_FILES =	tree_tests_capacity.cpp \
					tree_tests_comp_ops.cpp \
					tree_tests_construct.cpp \
					tree_tests_elements.cpp \
					tree_tests_iterators.cpp \
					tree_tests_modifiers.cpp \
					tree_tests_swap.cpp \
					tree_tests.cpp

VEC_SRC_FILES =		vector_test_capacity.cpp \
					vector_test_comp_ops.cpp \
					vector_test_construct.cpp \
					vector_test_elements.cpp \
					vector_test_iterator.cpp \
					vector_test_modifiers.cpp \
					vector_test_swap.cpp \
					vector_tests.cpp

# DIRECTORIES

IMPL_DIR =		ft_stl

INC_DIR =		tests/include
SRC_DIR =		tests/src
TEST_OUT_DIR =	tests/outputs
SUBDIRS =		iterator map set stack tree vector
SRC_SUBDIRS =	$(addprefix $(SRC_DIR)/, $(SUBDIRS))

OBJ_DIR =		obj

VPATH =			$(SRC_DIR) $(SRC_SUBDIRS)

# ALL SRC FILES

SRC_FILES =		$(CMP_SRC_FILES) $(MAP_SRC_FILES) $(VEC_SRC_FILES) $(STACK_SRC_FILES) $(SET_SRC_FILES) $(IT_SRC_FILES)
TREE_FILES =	$(addprefix $(SRC_DIR)/tree/, $(TREE_SRC_FILES))

# OBJ

OBJ_FILES = $(SRC_FILES:%.cpp=%.o)

OBJ =		$(addprefix $(OBJ_DIR)/ft/, $(OBJ_FILES))
OBJ_STD =	$(addprefix $(OBJ_DIR)/original/, $(OBJ_FILES))
OBJ_CMP =	$(addprefix $(OBJ_DIR)/cmp/, $(CMP_SRC_FILES:%.cpp=%.o))

# INC AND PATHS

INC = $(addprefix $(IMPL_DIR)/, $(IMPL_FILES)) \
	  $(addprefix $(INC_DIR)/, $(TEST_INC_FILES))

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
	./$(NAME_STD) > $(TEST_OUT_DIR)/original.out 2>&1
	./$(NAME) > $(TEST_OUT_DIR)/mine.out 2>&1
	./$(NAME_CMP)

debug_tree:
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TREE_FILES) $(addprefix $(SRC_DIR)/, $(CMP_SRC_FILES)) -o test_tree

test_tree:
	valgrind --leak-check=full ./test_tree

debug_42:
	$(CXX) -I$(IMPL_DIR) $(CXXFLAGS) main42.cpp -o test_42

check_leaks: $(NAME)
	valgrind --leak-check=full ./$(NAME)

show:
	@echo "OBJ_FILES\n$(OBJ_FILES)\n"
	@echo "INC\n$(INC)\n"

# CLEAN

clean:
	$(RM) -rf $(OBJ_DIR) $(TEST_OUT_DIR)

fclean: clean
	$(RM) -f $(NAME) $(NAME_STD)

re: fclean all

.PHONY: all debug show clean fclean re test_tree
