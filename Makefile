CC = gcc
FLAGS = -Wall -Wextra -Werror -O3
NAME = fractol
SRC =	main.c\
		hook.c\
		expose.c\
		env.c\
		env_bis.c\
		load_kernel.c\
		run_cl.c\
		host.c\
		color.c\

OBJ = $(SRC:.c=.o)
INCLUDE = ./includes
LIB = -L ./libft -lft -lmlx -framework OpenGL -framework AppKit -framework OpenCL

all: $(NAME)

$(NAME): ./libft/libft.a $(OBJ) 
	$(CC) -o $(NAME) $(OBJ) -I $(INCLUDE) $(LIB) $(FLAGS)

./libft/libft.a: 
	make -C libft

%.o: %.c
	$(CC) -o $@ -c $< -I $(INCLUDE) $(FLAGS)

clean:
	rm -f $(OBJ)
	make -C libft/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
