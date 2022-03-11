SRCS		=	main.cpp \
				Form.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				Intern.cpp \
				Bureaucrat.cpp

OBJS		= ${SRCS:.cpp=.o}

DEP			= ${OBJS:.o=.d}

NAME		= Bureaucratv4

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
	${RM} *_shrubbery

re:				fclean all

-include ${DEP}

.PHONY:			all clean fclean re
