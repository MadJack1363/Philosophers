# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majacque <majacque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 15:09:55 by majacque          #+#    #+#              #
#    Updated: 2022/01/21 15:14:11 by majacque         ###   ########.fr        #
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
SRC_DIR				=	srcs/
OBJ_DIR				=	objs/
PRV_DIR				=	private/

######################################
#            SOURCE FILES            #
######################################
SRC				=	\

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
CFLAGS			+=	-MMD -MP

LDFLAGS			=

ifeq (${DEBUG}, 1)
	CFLAGS		+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}: ${OBJ}
	${LINK} $@ ${OBJ} ${LDFLAGS}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJ_DIR} ${NAME}

re: clean all

.PHONY: all clean fclean re fre
