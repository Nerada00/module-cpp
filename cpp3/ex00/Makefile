SRCS = 	main.cpp\
		ClapTrap.cpp\

OBJS = $(SRCS:.cpp=.o)
NAME = ex00
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.
RM = rm -f

all: $(NAME)
	@echo
	@echo "\033[32m=========== Success =========== \033[0m"
	@echo
$(NAME): $(OBJS)
	@$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo
	@echo "\033[33m======== OBJS removed ========= \033[0m"
	@echo

fclean:
	@$(RM) $(NAME) $(OBJS)
	@echo
	@echo "\033[31m======= All was removed ======= \033[0m"
	@echo

re: fclean all

.PHONY: clean fclean all re
