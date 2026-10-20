# ---- Ce que tu adaptes à chaque exercice ----
NAME    = account
SRCS    = tests.cpp Account.cpp
# ---------------------------------------------

CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = Account.hpp

OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re