##
## Makefile for Makefile in /home/catuss_a//Desktop/my_script
## 
## Made by axel catusse
## Login   <catuss_a@epitech.net>
## 
## Started on  Fri Feb 25 17:42:01 2011 axel catusse
## Last update Sun Mar 27 23:11:14 2011 axel catusse
##

NAME		=	epikong_etape_2
CC		=	gcc
RM		=       rm -f
CFLAGS		+=	-W -Wall `sdl-config --cflags`
IFLAGS		=	-I./include
LDFLAGS		=	`sdl-config --libs` -lSDL_image -lSDL_gfx -lm -g -g3 -ggdb
OBJS		=	$(SRCS:.c=.o)
DIR_SRCS	=	./src/


################################################################################################
SRCS		=	$(DIR_SRCS)main.c				\
			$(DIR_SRCS)my_error.c				\
			$(DIR_SRCS)xmalloc.c				\
			$(DIR_SRCS)move_hero.c				\
			$(DIR_SRCS)move_camera.c			\
			$(DIR_SRCS)move_monster.c			\
			$(DIR_SRCS)do_move.c				\
			$(DIR_SRCS)move_space.c				\
			$(DIR_SRCS)move_rightleft.c			\
			$(DIR_SRCS)gravity_hero.c			\
			$(DIR_SRCS)init_game.c				\
			$(DIR_SRCS)add_to_herolist.c			\
			$(DIR_SRCS)add_to_objectlist.c			\
			$(DIR_SRCS)add_to_monsterlist.c			\
			$(DIR_SRCS)fill_anime_robot.c			\
			$(DIR_SRCS)clear_screen.c			\
			$(DIR_SRCS)init_sdl.c				\
			$(DIR_SRCS)map.c				\
			$(DIR_SRCS)x_IMG_Load.c \
			$(DIR_SRCS)display_background.c \
			$(DIR_SRCS)display_fall.c \
			$(DIR_SRCS)display_grimper.c \
			$(DIR_SRCS)display_hero.c \
			$(DIR_SRCS)display_idle.c \
			$(DIR_SRCS)display_jump.c \
			$(DIR_SRCS)display_life.c \
			$(DIR_SRCS)display_monster.c \
			$(DIR_SRCS)display_object.c \
			$(DIR_SRCS)display_runright.c \
			$(DIR_SRCS)display_runleft.c \
			$(DIR_SRCS)display_runleft_robot.c \
			$(DIR_SRCS)display_runright_robot.c \
			$(DIR_SRCS)handles_keys.c \
			$(DIR_SRCS)init_cam.c \
			$(DIR_SRCS)handles_event.c \
			$(DIR_SRCS)fill_anime_jazz.c \
			$(DIR_SRCS)display_screen.c \
			$(DIR_SRCS)get_next_line.c


################################################################################################
$(NAME)		:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(IFLAGS) $(LDFLAGS)

all             :       $(NAME)

clean           :
		$(RM) $(OBJS)
		rm -rf *~
		rm -rf *#

fclean		:	clean
		$(RM) $(NAME)

re              :       fclean all

.c.o		:
		$(CC) $(IFLAGS) $< -c -o $@ $(CFLAGS)

.PHONY		:	all clean fclean re

.SUFFIXES	:	.c .o
################################################################################################