# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 13:07:02 by fmaqdasi          #+#    #+#              #
#    Updated: 2023/12/05 13:06:38 by fmaqdasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
AR				= ar rcs
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

FILES	=	ft_printf.c ft_printf_fun.c ft_printf_p.c ft_printf_cs.c ft_printf_du.c ft_printf_xX.c
					
OBJS	= $(addsuffix .o,$(basename $(FILES)))


all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

clean:			
				$(RM) $(OBJS) $(OBJSB)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME) 
	

.PHONY:			all clean fclean re