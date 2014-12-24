##
## Makefile
##
## Made by vincent leroy
## Login   <leroy_v@epitech.eu>
##
## Started on  Wed Dec 24 15:00:49 2014 vincent leroy
## Last update Wed Dec 24 15:03:12 2014 vincent leroy
##

SRC			= main.cpp \
			  treeflags.cpp \
			  treenode.cpp

CXXFLAGS	= -Wall -Wextra

LDFLAGS		=

NAME		= tree
NAME_DEBUG	= $(NAME).debug

OBJ			= $(SRC:.cpp=.o)
OBJ_DEBUG	= $(SRC:.cpp=.debug.o)

RM			= rm -f

CXX			= g++

MAKE		= make -C

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_DEBUG) *.swp *~ *#

fclean: clean
	$(RM) $(NAME) $(NAME_DEBUG)

re: fclean all

debug: CXXFLAGS += -ggdb3
debug: $(OBJ_DEBUG)
	$(CXX) $(OBJ_DEBUG) $(LDFLAGS) -o $(NAME_DEBUG)

%.debug.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean fclean re debug
