NAME_C = client
NAME_S = server
NAME_C_BONUS = client_bonus
NAME_S_BONUS = server_bonus

SRC_C = src/client.c
SRC_S = src/server.c
SRC_C_BONUS = src/client_bonus.c
SRC_S_BONUS = src/server_bonus.c

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJ_C_BONUS = $(SRC_C_BONUS:.c=.o)
OBJ_S_BONUS = $(SRC_S_BONUS:.c=.o)

LIBFT = ./Libft/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ar rcs
RM = rm -fr

all:				$(NAME_C) $(NAME_S)

$(NAME_C):			$(SRC_C) $(LIBFT)
						$(CC) $(CFLAGS) $(SRC_C) -o $(NAME_C) $(LIBFT)

$(NAME_S):			$(SRC_S) $(LIBFT)
						$(CC) $(CFLAGS) $(SRC_S) -o $(NAME_S) $(LIBFT)

bonus:				$(NAME_C_BONUS) $(NAME_S_BONUS)

$(NAME_C_BONUS):	$(SRC_C_BONUS) $(LIBFT)
						$(CC) $(CFLAGS) $(SRC_C_BONUS) -o $(NAME_C_BONUS) $(LIBFT)

$(NAME_S_BONUS):	$(SRC_S_BONUS) $(LIBFT)
						$(CC) $(CFLAGS) $(SRC_S_BONUS) -o $(NAME_S_BONUS) $(LIBFT)

clean:
				make clean -s -C $(LIBFT)

fclean:			clean
					$(RM) $(NAME_C) $(NAME_S) $(NAME_C_BONUS) $(NAME_S_BONUS)
					make fclean -s -C $(LIBFT)

re:				fclean all

.PHONY:			 all re clean fclean bonus