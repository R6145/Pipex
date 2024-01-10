# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 18:19:18 by fmaqdasi          #+#    #+#              #
#    Updated: 2024/01/10 17:45:47 by fmaqdasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := pipex
CC          := cc
CFLAGS       := -Wall -Wextra -Werror -fsanitize=address -g3
RM		    := rm -f
INCLUDE = -Ift_printf/ -Ilibft/
LIBFT_DIR = libft/
PRINTF_DIR = printf/
PRINTF = printf/libftprintf.a
LIBFT = libft/libft.a

SRCS        := 				pipex_util.c \


SRCSM1       :=            pipex.c \


                          
OBJS        := $(SRCS:.c=.o)
OBJSNAME    := $(SRCSM1:.c=.o)

LIBS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) $(LIBFT) $(PRINTF)

.c.o:
	@${CC} ${CFLAGS} $(INCLUDE) -c $< -o $@
	
    
${NAME}:	${OBJS} ${OBJSNAME} $(LIBFT) $(PRINTF) $(MINILIBX)
			@${CC} ${CFLAGS} $(INCLUDES) ${OBJS} ${OBJSNAME} $(LIBS) -o ${NAME} 
			@echo "\033[0;32mPIPEX compiled successfully"
$(LIBFT):
	        @make -C $(LIBFT_DIR) -s
			@echo "\033[0;32mLibft compiled successfully"


$(PRINTF):
			@make -C $(PRINTF_DIR) -s
			@echo "\033[0;32mPrintf compiled successfully"


all:		${NAME}

clean:
			@${RM} *.o
			@make -C $(LIBFT_DIR) clean -s
			@make -C $(PRINTF_DIR) clean -s
			@echo "\033[0;31mObjects removed successfully"


fclean:		clean
			@${RM} ${NAME}
			@make -C $(LIBFT_DIR) fclean -s
			@make -C $(PRINTF_DIR) fclean -s
			@echo "\033[0;31mAll created objects were removed successfully"

re:			fclean all
			@echo "\033[0;32mPIPEX was recompiled successfully"

.PHONY:		all clean fclean re bonus