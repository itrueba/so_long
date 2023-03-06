
NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3
RM			= rm -rf
LIB			= Libft

SRCS	=	$(shell find . -name "*.c")

OBJS	= 	$(SRCS:.c=.o)

all:		$(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) 
			make -C $(LIB)
			mv $(LIB)/libft.a $(NAME)
			$(CC) $(CFLAGS) -o $@ $^

clean:
			@make -C $(LIB) clean
			@$(RM) $(OBJS)

fclean:		clean
			@make -C $(LIB) fclean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

