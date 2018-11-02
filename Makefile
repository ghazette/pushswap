# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: gzanarel <gzanarel@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/09/26 10:26:49 by gzanarel     #+#   ##    ##    #+#        #
#    Updated: 2018/10/30 10:28:57 by gzanarel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap
INC = include/

LIB_DIR = ./libft

SRC = srcs/tools.c \
	srcs/checker.c \
	srcs/init.c \
	srcs/push_check.c \
	srcs/operation.c \
	srcs/apply_ope.c \
	srcs/algo_min.c \
	srcs/algo_max.c \
	srcs/tools_algo.c \
	srcs/real_quick.c \

MAIN_C = srcs/main_c.c
MAIN_PS = srcs/main_ps.c

OBJ = $(addprefix ,$(SRC:.c=.o))
OBJC = $(addprefix ,$(MAIN_C:.c=.o))
OBJPS = $(addprefix ,$(MAIN_PS:.c=.o))

L_FT = $(LIB_DIR)
LIB_LNK = -L $(L_FT) -lft
LIB_INC	= -I $(L_FT)/libft.h

FLAGS = -Werror -Wextra -Wall

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(NAME2)
	@gcc $(OBJC) -I $(INC) $(OBJ) $(LIB_LNK) $(FLAGS) -o $(NAME)
	@echo "\n\033[32;01m./checker.. done !\033[00m\n"

$(NAME2): $(OBJ) $(OBJC) $(OBJPS)
	@$(MAKE) -C libft/
	@gcc $(OBJPS) -I $(INC) $(OBJ) $(LIB_LNK) $(FLAGS) -o $(NAME2)
	@echo "\n\033[32;01m./push_swap.. done !\033[00m\n"

%.o:%.c $(INC)
	gcc -I $(INC) -c $(MAIN_C) -o $@

%.o:%.c $(INC)
	gcc -I $(INC) -c $(MAIN_PS) -o $@

%.o:%.c $(INC)
	gcc -I $(INC) -c $< -o $@

clean:
	@rm -rf srcs/*.o
	@rm -rf $(L_FT)/objs/*.o
	@echo "\n\033[31;01mClean..\033[00m\n"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME2)	
	@rm -rf $(L_FT)/libft.a
	@echo "\n\033[31;01mFclean..\033[00m\n"

re: fclean all
