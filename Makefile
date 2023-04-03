SRC=    src/computor.cpp src/parsing.cpp src/utils.cpp \

OBJS			= $(SRC:.cpp=.o)

NAME			= computor-V1

CFLAGS			= -Wall -Wextra -Werror -std=c++98

RM				= rm -f

CC				= c++

%.o : %.cpp
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L.

all:			$(NAME)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean c.o re 