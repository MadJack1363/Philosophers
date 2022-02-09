# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majacque <majacque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 15:09:55 by majacque          #+#    #+#              #
#    Updated: 2022/02/09 03:10:37 by majacque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC					=	cc -c -o
LINK				=	cc -o
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
					data_philo.c		\
					fork_stick.c		\
					ft_atoi.c			\
					ft_bzero.c			\
					ft_calloc.c			\
					ft_intlen.c			\
					ft_isdigit.c		\
					ft_iswspace.c		\
					ft_itoa.c			\
					ft_strcmp.c			\
					inputs.c			\
					is_state.c			\
					main.c				\
					philo_die.c			\
					philo_eat.c			\
					philo_set_state.c	\
					philo_sleep.c		\
					philo_talk.c		\
					philo_think.c		\
					philo_wait.c		\
					philos.c			\
					routine.c			\
					run_simulation.c	\
					time.c				\

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
	CFLAGS		+=	-g3
endif

ifeq (${THREAD}, 1)
	CFLAGS		+= -g3 -fsanitize=thread
	LDFLAGS		+= -ltsan
endif

#######################################
#              VARIABLES              #
#######################################
VG_OPT = --leak-check=full --log-file="output"
HG_OPT = --log-file="output" --tool=helgrind
DRD_OPT = --log-file="output" --tool=drd

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
	${RM} ${OBJ_DIR}

fclean:
	${RM} ${OBJ_DIR} ${NAME}

re: fclean all

valgrind:
	${MAKE} ${NAME} DEBUG=1
	@read -p "arguments: " arguments;	\
	$@ ${VG_OPT} ./${NAME} $$arguments

helgrind:
	${MAKE} ${NAME} DEBUG=1
	@read -p "arguments: " arguments;	\
	valgrind ${HG_OPT} ./${NAME} $$arguments

drd:
	${MAKE} ${NAME} DEBUG=1
	@read -p "arguments: " arguments;	\
	valgrind ${DRD_OPT} ./${NAME} $$arguments

.PHONY: all clean fclean re fre valgrind helgrind drd
