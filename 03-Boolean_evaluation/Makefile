NAME=evaluation
OBJS=main.o
CXX=clang++
RM=rm -rf
CXXFLAGS=-Wall -Wextra -Werror
SRCS=main.cpp

OBJS=$(SRCS:.cpp=.o)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)
	$(RM) result.log

fclean: clean
	$(RM) $(NAME)

re: fclean all

//.PHONY: all $(NAME) clean fclean re