##
## Makefile for Makefile in /home/genaud_p/SystemeUnix/client_graphique_zappy
## 
## Made by Pierre Genaudeau
## Login   <genaud_p@epitech.net>
## 
## Started on  Mon Jun 23 16:39:44 2014 Pierre Genaudeau
## Last update Sun Jul 13 17:26:26 2014 Pierre Genaudeau
##

NAME		=	client_graphique

DIR		=	srcs/

SRC		=	$(DIR)main.cpp		\
			$(DIR)Display.cpp	\
			$(DIR)Floor.cpp		\
			$(DIR)Perso.cpp		\
			$(DIR)Mineral.cpp	\
			$(DIR)Fond.cpp		\
			$(DIR)Food.cpp		\
			$(DIR)Egg.cpp		\
			$(DIR)Client.cpp	\

OBJ		=	$(SRC:.cpp=.o)

CFLAGS		=	-W -Wall -Werror

RM		=	rm -f

CC		=	g++

INCLUDE		=	-I./includes -I./SFML/include -I./glew/include/GL -I./includes

LDFLAGS		=	-L./Lib/ -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLEW

all		:	$(NAME)
			@echo "Exporting glew/sfml"
			@echo export LD_LIBRARY_PATH=./Lib/

$(NAME)		:	$(OBJ)
		  	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean		:
		  	$(RM) $(OBJ)

fclean		: 	clean
			$(RM) $(NAME)

re		: 	fclean all

.cpp.o		:
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
