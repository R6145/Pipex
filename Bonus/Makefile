# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 18:19:18 by fmaqdasi          #+#    #+#              #
#    Updated: 2024/01/11 00:54:12 by fmaqdasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := pipex
CC          := cc
CFLAGS       := -Wall -Wextra -Werror
RM		    := rm -f
INCLUDE = -Ilibft/
LIBFT_DIR = libft/
LIBFT = libft/libft.a

SRCS        := 				pipex_util.c \
							pipex_util2.c \
							pipex_util3.c \


SRCSM1       :=            pipex.c \


                          
OBJS        := $(SRCS:.c=.o)
OBJSNAME    := $(SRCSM1:.c=.o)

LIBS = -L$(LIBFT_DIR) $(LIBFT)

.c.o:
	@${CC} ${CFLAGS} $(INCLUDE) -c $< -o $@
	
    
${NAME}:	${OBJS} ${OBJSNAME} $(LIBFT) $(PRINTF) $(MINILIBX)
			@${CC} ${CFLAGS} $(INCLUDES) ${OBJS} ${OBJSNAME} $(LIBS) -o ${NAME} 
			@echo "\033[0;32mPIPEX compiled successfully"
$(LIBFT):
	        @make -C $(LIBFT_DIR) -s
			@echo "\033[0;32mLibft compiled successfully"


all:		${NAME}

clean:
			@${RM} *.o
			@make -C $(LIBFT_DIR) clean -s
			@echo "\033[0;31mObjects removed successfully"


fclean:		clean
			@${RM} ${NAME}
			@make -C $(LIBFT_DIR) fclean -s
			@echo "\033[0;31mAll created objects were removed successfully"

re:			fclean all
			@echo "\033[0;32mPIPEX was recompiled successfully"

.PHONY:		all clean fclean re bonus