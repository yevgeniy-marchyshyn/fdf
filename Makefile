# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/10 18:08:28 by ymarchys          #+#    #+#              #
#    Updated: 2018/03/30 18:20:27 by ymarchys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -lmlx -framework OpenGL -framework AppKit

FDF = main.c\
	  fdf_error.c\
	  manage_control_keys.c\
	  click_x.c\
	  draw_map.c\
	  put_pixel.c\
	  apply_multiplier.c\
	  set_offset.c\
	  reset_offset.c\
	  line_bresenham.c\
	  map_rotation.c\
	  move_map.c\
	  multiply_axis_z.c\
	  annulation_fdf.c\
	  joiner.c\
	  write_z.c\
	  is_valid.c\
	  free_before_exit.c\
	  z_plus.c\
	  zooming.c\

OBJ = $(FDF: .c = .o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Compiling FDF"
	@gcc $(FLAGS) $(FDF) ./libft/libft.a -o $(NAME)
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Done"

clean:
	@make -C ./libft/ clean

fclean: clean
	@make -C ./libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
