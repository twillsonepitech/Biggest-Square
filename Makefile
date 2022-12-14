# START of Makefile color and typo of messages
_END='\033[0m'
_BOLD='\033[1m'
_UNDER='\033[4m'

_RED='\033[31m'
_GREEN='\033[32m'
_YELLOW='\033[33m'
_BLUE='\033[34m'
# END	of Makefile color and typo of messages

CC	?=	gcc

MAKE	?=	make

RM	?=	rm -rf

STATIC_LIB_FOLDERS	=	Lib-IO
LDLIBS				+=	-lio
LDFLAGS				+=	${addprefix -L ./, ${STATIC_LIB_FOLDERS}}

NAME	:=	biggest-square
MOVE	:=	mv

TESTS_BIN				:=	*.gc*
TESTS_BIN_NAME			:=	unit_tests
TESTS_LIBS				:=	-lcriterion --coverage
TESTS_FUNCTIONAL_NAME	:=	functional_bsq_tests.sh

CPPFLAGS	+=	-iquote ./includes
CPPFLAGS	+=	${addprefix -iquote ./, ${addsuffix ./includes, ${STATIC_LIB_FOLDERS}}}
CFLAGS		+=	-Wall -Wextra -Werror -fPIC -pedantic

MAIN	=	${addsuffix .c, ${addprefix ./, main}}
SRCS	=	${addsuffix .c,								\
				${addprefix srcs/, exec_bsq array	\
				error_handling algorithm }	\
			}

ALL_SRCS	:=	${MAIN}
ALL_SRCS	+=	${SRCS}

TESTS_SRCS	:=	${SRCS}
TESTS_SRCS	+=	${addsuffix .c,								\
					${addprefix tests/tests_, }	\
				}								\

OBJS	=	${ALL_SRCS:.c=.o}
TESTS_OBJS	:=	${TESTS_SRCS:.c=.o}

%.o : %.c
	@$ ${CC} ${CFLAGS} ${CPPFLAGS} -c $< -o $@
	@echo "${CC} ${CFLAGS} ${CPPFLAGS} -c $< -o $@ ["${_GREEN}"OK"${_END}"]"
.SUFFIXES: .o .c

all:	dependencies ${NAME}

${NAME}:	${OBJS}
	@${CC} ${OBJS} ${LDFLAGS} ${LDLIBS} -o ${NAME}

dependencies:
	for folder in ${STATIC_LIB_FOLDERS} ; do \
		${MAKE} -C $$folder static ; \
	done

clean:
	${RM} ${OBJS}
	${RM} ${NAME}
	${RM} *.so
	${RM} *.out
	for folder in ${STATIC_LIB_FOLDERS} ; do \
		${MAKE} -C $$folder clean ; \
	done

fclean:	clean
	${RM} ${TESTS_OBJS}
	${RM} ${TESTS_BIN_NAME}
	${RM} ./srcs/${TESTS_BIN}
	${RM} ./tests/${TESTS_BIN}
	${RM} ./tests/${NAME}
	for folder in ${STATIC_LIB_FOLDERS} ; do \
		${MAKE} -C $$folder fclean ; \
	done

re:	fclean all

debug:	CFLAGS	+=	-g3
debug:	re

# tests_run:	${TESTS_OBJS}
# 	${CC} ${TESTS_LIBS} ${TESTS_OBJS} -o ${TESTS_BIN_NAME}
# 	./${TESTS_BIN_NAME}
# 	${RM} ${TESTS_OBJS}
# 	${RM} ${TESTS_BIN_NAME}
tests_run: re
	${MOVE} ${NAME} ./tests && cd ./tests && ./${TESTS_FUNCTIONAL_NAME} && cd ..

valgrind:	CFLAGS	+=	-g3
valgrind:	${TESTS_OBJS}
	${CC} ${TESTS_LIBS} ${TESTS_OBJS} -o ${TESTS_BIN_NAME}
	valgrind --trace-children=yes --quiet ./${TESTS_BIN_NAME}
	${RM} ${TESTS_OBJS}
	${RM} ${TESTS_BIN_NAME}

.PHONY:	all clean fclean re debug tests_run valgrind
