NAME 			= so_long
CC				= gcc 
SRCS			= $(addprefix ./src/, main.c \
									init_game.c \
									init_map.c \
									utils.c \
									error_handling.c)

OBJS			= $(SRCS:.c=.o)
HEADER			= -I ./includes
MLX				= MLX42/build/libmlx42.a
MLX_HEADER		= -I MLX42/include/MLX42/MLX42.h 
LIBFT			= Libft/libft.a
LDFLAGS			+= -L/usr/local/lib -lglfw
CFLAGS			+= -Wall -Wextra -Werror $(HEADER) -I/usr/local/include
DEPENDENCIES	= -ldl -lglfw -pthread -lm

all:		$(NAME)

GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

$(LIBFT):
			@make -C ./Libft

$(MLX):
			@cd MLX42 && cmake -B build && cmake --build build -j4

$(NAME):	$(OBJS) $(MLX) $(LIBFT) 
				@$(CC) $(OBJS) $(MLX) $(LIBFT) $(MLX_HEADER) $(DEPENDENCIES) $(LDFLAGS) -o $(NAME)
				@echo "$(GREEN)Compilation of '$(NAME)' successful$(NC)"

%.o:%.c 
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -f $(OBJS)
			@rm -rf MLX42/build
			make fclean -C ./Libft
			@echo "$(BLUE) Removed object files$(NC)"

fclean:		clean
			@rm -f $(NAME)
			@echo "$(NAME) Program was removed$(NC)"

re:			fclean all
			@echo "$(GREEN) Program was recompiled$(NC)"

.PHONY:		all clean flean re 


#######################################################
#compilation only works in terminal outside of vscode!#