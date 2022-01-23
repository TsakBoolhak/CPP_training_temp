SRCS		=	Contact.class.cpp \
				PhoneBook.class.cpp \
				main.cpp

OBJS		= ${SRCS:.cpp=.o}

DEP			= ${OBJS:.o=.d}

NAME		= phonebook

CC			= c++

CFLAGS		= -MMD -Wall -Wextra -Werror -std=c++98 -I.

RM			= rm -f

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:		 ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -pthread -o ${NAME}

all:			${NAME}

clean:
	${RM} ${OBJS} ${DEP}

fclean:			clean
	${RM} ${NAME}

re:				fclean all

re_bonus:		fclean_bonus bonus

-include ${DEP}

.PHONY:			all clean fclean re
