SRCS		=	megaphone.cpp

OBJS		= ${SRCS:.cpp=.o}

NAME		= megaphone

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

RM			= rm -f

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:		 ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
	${RM} ${OBJS}

fclean:			clean
	${RM} ${NAME}

re:				fclean all

re_bonus:		fclean_bonus bonus

.PHONY:			all clean fclean re
