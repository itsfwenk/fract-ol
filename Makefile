# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fli <fli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 10:09:37 by fli               #+#    #+#              #
#    Updated: 2024/07/18 17:27:02 by fli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program name
NAME	= fractol

# Compiler
CC		= cc -g3
CFLAGS	= -Werror -Wextra -Wall

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./includes/\
				-I ./libft/\
				-I ./minilibx-linux/

# Sources
SRC_PATH	=	src/
SRC			=	burnship_calc.c \
				color_fractol.c \
				draw_fract.c \
				fractol_utils.c \
				fractol.c \
				ft_atod.c \
				init_fractol.c \
				julia_calc.c \
				key_event.c \
				mandel_calc.c \
				print_guide.c \
				pxtod.c \
				zoom.c \

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/
	@mkdir $(OBJ_PATH)color_schemes/

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm -o $(NAME)
	@echo "Fractol ready."

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@rm -f $(OBJ)
	@rm -f $(LIBFT_NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean
