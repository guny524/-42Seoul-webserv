NAME		=	webserv
CXX			=	c++

HD_DIR		=	includes/
SRC_DIR		=	srcs/
# MLX_DIR		=	minilibx_opengl_20191021

SRC_ORI		=	main.cpp

SRC			=	$(addprefix $(SRC_DIR), $(SRC_ORI))
OBJ			=	$(SRC:.cpp=.o)

CFLAGS		+=	-std=c++98 -Wall -Wextra -Werror # -g -fsanitize=address
CXXFLAGS	+=	-I $(HD_DIR) # -I $(MLX_DIR)
LIBADD		+=	# -lm -lmlx -framework OpenGL -framework Appkit -lpthread
LDFLAGS		+=	# -L$(MLX_DIR)

all:		$(NAME)

%.o:		%.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
# @make -C $(MLX_DIR) 2> /dev/null
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(LDFLAGS) $(LIBADD) $^ -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ:.o=.d)
# @make -C $(MLX_DIR) clean 2> /dev/null

fclean:		clean
	rm -f $(NAME)

re:
	make fclean
	make all

test:
# TODO

.PHONY:		all clean fclean re test

-include $(SRC:.cpp=.d)
