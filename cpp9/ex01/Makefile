SRCS = 	main.cpp\
		RPN.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = RPN
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.
RM = rm -f

all: $(NAME)
$(NAME): $(OBJS)
	@$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)
	@echo
	@echo "\033[32m=========== Success =========== \033[0m"
	@echo

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
	@echo "\033[31m======= all was removed ======= \033[0m"
	@echo

re: fclean all

.PHONY: clean fclean all re