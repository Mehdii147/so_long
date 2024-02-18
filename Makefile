# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 16:05:09 by ehafiane          #+#    #+#              #
#    Updated: 2024/02/18 14:24:50 by ehafiane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIBFT = libft.a
NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra 
SRC_DIR = ./mandatory/
SRC_DIR_BONUS = ./bonus/
OBJ_DIR = ./obj/

SRC_FILES = main.c get_map.c get_next_line.c get_next_line_utils.c map_check.c valid_acces.c \
			player_moves.c so_long.c  utils.c libft_utils.c puts.c
SRC_FILES_BONUS = main_bonus.c get_map_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c map_check_bonus.c valid_acces_bonus.c \
			player_moves_bonus.c so_long_bonus.c  utils_bonus.c enemy_update_bonus.c libft_utils_bonus.c puts_bonus.c
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_FILES_BONUS = $(SRC_FILES_BONUS:.c=.o)

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJ_BONUS = $(addprefix $(OBJ_DIR), $(OBJ_FILES_BONUS))




all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I inc/so_long.h -L. -lmlx -framework OpenGL -framework AppKit
	@echo "\033[4;35m                                                            \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███   ███  ▄███            \n\
	███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      \n\
	        ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     \n\
	▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀      \n\
                                                                       	 		\033[0m"
	@echo "                               					 \033[4:35m By: ACE"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c inc/so_long.h inc/get_next_line.h 
	@mkdir -p obj
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
$(NAME_BONUS): $(OBJ_BONUS) 
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) -I inc/so_long_bonus.h -L. -lmlx -framework OpenGL -framework AppKit
	@echo "\033[4;35m                                                            \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███   ███  ▄███            \n\
	███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      \n\
	        ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     \n\
	▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀      \n\
                                                                       	 		\033[0m"
	@echo "                               					 \033[4:35m By: ACE"

$(OBJ_DIR)%_bonus.o: $(SRC_DIR_BONUS)%_bonus.c inc/so_long_bonus.h inc/get_next_line_bonus.h 
	@mkdir -p obj
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)
