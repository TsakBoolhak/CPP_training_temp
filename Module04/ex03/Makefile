SRCS		=	main.cpp \
				AMateria.cpp \
				Character.cpp \
				Cure.cpp \
				Ice.cpp \
				Inventory.cpp \
				MateriaSource.cpp

OBJS		= ${SRCS:.cpp=.o}

DEP			= ${OBJS:.o=.d}

NAME		= Materias

CC			= c++

CFLAGS		= -MMD -Wall -Wextra -Werror -std=c++98 -g3 -I.

RM			= rm -f

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:		 ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
	${RM} ${OBJS} ${DEP}

fclean:			clean
	${RM} ${NAME}

re:				fclean all

-include ${DEP}

.PHONY:			all clean fclean re
