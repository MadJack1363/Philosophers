# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majacque <majacque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 15:09:55 by majacque          #+#    #+#              #
#    Updated: 2022/01/24 18:16:38 by majacque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC					=	clang -c -o
LINK				=	clang -o
MKDIR				=	mkdir -p
RM					=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME				=	philosophers

#######################################
#             DIRECTORIES             #
#######################################
OBJ_DIR				=	objs/

######################################
#            SOURCE FILES            #
######################################
SRC				=	\
					ft_atoi.c		\
					ft_bzero.c		\
					ft_calloc.c		\
					ft_intlen.c		\
					ft_isdigit.c	\
					ft_iswspace.c	\
					ft_itoa.c		\
					ft_strcmp.c		\
					inputs.c		\
					main.c			\

######################################
#            OBJECT FILES            #
######################################
OBJ				=	${SRC:.c=.o}
OBJ				:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP				=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS			+=	-MMD -MP -pthread

LDFLAGS			= -pthread

ifeq (${DEBUG}, 1)
	CFLAGS		+=	-g
endif

#######################################
#              VARIABLES              #
#######################################
VG_OPT = --tool=helgrind

#######################################
#                RULES                #
#######################################
${NAME}: ${OBJ}
	${LINK} $@ ${OBJ} ${LDFLAGS}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: %.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJ_DIR} ${NAME}

re: clean all

valgrind:
	${MAKE} ${NAME} DEBUG=1
	@read -p "arguments: " arguments;	\
	$@ ${VG_OPT} ./${NAME} $$arguments

.PHONY: all clean fclean re fre valgrind
