NAME 		= so_long
CC			= cc 
CFLAGS		= -Wall -Wextra -Werror
SRCS		= main.c \
OBJS		= $(SRCS:.c=.o)
HEADER		= so_long.h
GLFW_DIR	= 
MLX			= MLX42/build/libmlx42.a
MLX_HEADER	= MLX42/include/MLX42/MLX42.h 
LIBFT		= Libft/libft.a

all:		$(NAME)

GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

$(LIBFT):
			@make -C ./Libft

$(MLX):		@cd MLX42 && cmake -B build && cmake --build build -j4

$(NAME):	$(OBJS) $(MLX) $(LIBFT) $(HEADER)
				@$(CC) $(OBJS) $(MLX) $(LIBFT) -ldl -pthread -lm -L$(GLFW_DIR) -lglfw -I $(MLX_HEADER) -o $(NAME)
				@echo "$(GREEN)Compilation of '$(NAME)' successful$(NC)"

%.o:%.c 
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -f $(OBJS)
			@rm -rf MLX42/build
			make fclean -C ./Libft
			@echo "$(BLUE)Removed object files$(NC)"

fclean:		clean
			@rm -f $(NAME)
			@echo "$(NAME)Program was removed$(NC)"

re:			fclean all
			@echo "$(GREEN)Program was recompiled$(NC)"

.PHONY:		all clean flean re 