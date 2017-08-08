# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gselbo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/26 21:03:13 by gselbo            #+#    #+#              #
#    Updated: 2017/03/12 23:32:37 by gselbo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	fractol
MLX_DIR     =	mlx/
MLX			=	$(MLX_DIR)libmlx.a

LIBFT_DIR   =	libft/
LIBFT_LIB   =	libft.a
LIBFT_INC   =	includes
LIB			=	$(LIBFT_DIR)$(LIBFT_LIB)

CC          =	gcc

CFLAGS      =	-Wall -Werror -Wextra -O3
GFLAGS      =	-L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit 
FLAGS       =	$(CFLAGS) $(GFLAGS)

SRC_DIR     =	src
SRC_FILE    =	fractol.c mandelbrot.c color.c julia.c keyhook.c mousehook.c
SRCS        =	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR     =	obj
OBJ_FILE    =	$(SRC_FILE:.c=.o)
OBJS        =	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

INC_DIR     =	-I inc -I $(MLX_DIR) -I $(LIBFT_DIR)$(LIBFT_INC)

.PHONY: all clean fclean re libft mlx

all: $(MLX) $(LIB) $(NAME)

$(NAME): $(SRCS) | $(OBJS) 
	$(CC) $(FLAGS) $(LIB) $(OBJS) $(INC_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -c $^ $(CFLAGS) $(INC_DIR) -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@cd $(LIBFT_DIR) && make clean
	@cd $(MLX_DIR) && make clean

fclean:
	@rm -rf $(OBJ_DIR)
	@cd $(MLX_DIR) && make clean
	@rm -f $(NAME)
	@cd $(LIBFT_DIR) && make fclean

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)
