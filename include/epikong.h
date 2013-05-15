/*
** epikong.h for epikong in /home/catuss_a//Desktop/epikong
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Mar 26 01:47:41 2011 axel catusse
** Last update Sun Mar 27 22:52:33 2011 jason brillante
*/

#ifndef _EPIKONG_H_
# define _EPIKONG_H_

#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_rotozoom.h>
#include <math.h>

# define MAP1 "./map/map1"
# define MAP2 "./map/map2"
# define MAP3 "./map/map3"
# define MAP4 "./map/map4"
# define MAP5 "./map/map5"

# define BUFF_SIZE 1024
# define WIDTH 800
# define HEIGHT 600

# define WALL		'w'
# define BRUSH		'b'
# define EMPTY		'.'
# define LADDER		's'
# define KEY		'k'
# define OUTDOOR	'o'
# define MONSTER	'm'
# define INDOOR		'i'

# define DIE 0
# define LIVE 1

# define NORMAL_MODE	1

# define RUN_ANIM_SIZE	10

# define RUN_JAZZANIM_SIZE 8
# define IDLE_JAZZANIM_SIZE 39

# define WIDTH_ANIM_JAZZ 60
# define HEIGHT_ANIM_JAZZ 50

# define RUN_RIGHT 1
# define RUN_LEFT 2
# define IDDLE 3

typedef struct		s_coord
{
  int			x;
  int			y;
}			t_coord;

typedef struct		s_sprite
{
  SDL_Surface           *ptr;
  SDL_Rect              coord;
}			t_sprite;

typedef struct		s_sdl
{
  SDL_Surface           *ecran;
  SDL_Event             event;
  t_sprite		wall;
  t_sprite		ladder;
  t_sprite		jazzanime;
  t_sprite		background;
  t_sprite		robot;
  t_sprite		brush;
  t_sprite		key;
  t_sprite		outdoor;
}			t_sdl;

typedef struct		s_camera
{
  t_coord		lookat;
  int			scrollspeed;
}			t_camera;

typedef struct		s_sprite_anim
{
  t_coord		pos;
  int			w;
  int			h;
}			t_sprite_anim;

typedef struct		s_object
{
  char			type;
  t_coord		pos;
  struct s_object	*next;
}			t_object;

typedef struct		s_animation
{
  t_sprite_anim		runright[RUN_ANIM_SIZE + 1];
  t_sprite_anim		runleft[RUN_ANIM_SIZE + 1];
  t_sprite_anim		jump[RUN_ANIM_SIZE + 1];
  t_sprite_anim		fall[RUN_ANIM_SIZE + 2];
  t_sprite_anim		idle[54];
  t_sprite_anim		ladder[13];
}			t_animation;

typedef struct		s_char
{
  char			type;
  char			num;
  t_sprite		sprite;
  t_coord		pos;
  char			life;
  int			blink;
  int			grimper;
  int			yspeed;
  int			xspeed;
  t_object		*inv_l;
  t_animation		animation;
  float			idx_anim;
  struct s_char		*next;
}			t_char;

typedef struct		s_key
{
  char			esc;
  char			right;
  char			left;
  char			up;
  char			down;
  char			space;
}			t_key;

typedef struct		s_epikong
{
  t_sprite_anim		lifeanime[11];
  char			run;
  t_key			key;
  t_camera		camera;
  t_sdl			sdl;
  int			mode;
  int			level;
  char			**map;
  char			**allmap[5];
  t_coord		map_size;
  t_char		*hero_l;
  t_char		*monster_l;
  t_object		*objs_l;
}			t_epikong;

void			*xmalloc(int size);
char			*get_next_line(const int fd);
void			my_error(char *str, char live);
void			init_sdl(t_epikong *ekg);
void                    clean_screen(t_epikong *ekg);
void			init_map(t_epikong *ekg);
SDL_Surface		*x_IMG_Load(char *path);
void			display_background(t_epikong *ekg);
void			display_jump(t_epikong *ekg);
void			display_runright(t_epikong *ekg);
void			display_runleft(t_epikong *ekg);
void			display_idle(t_epikong *ekg);
void			display_fall(t_epikong *ekg, float *i);
void			display_grimper(t_epikong *ekg);
void			display_hero(t_epikong *ekg);
void			display_runright_robot(t_epikong *ekg, t_char *monster);
void			display_runleft_robot(t_epikong *ekg, t_char *monster);
void			display_monster(t_epikong *ekg);
void			display_object(t_epikong *ekg);
void			display_life(t_epikong *ekg);
void			display_screen(t_epikong *ekg);
void			init_camera(t_epikong *ekg);
void			handles_keydown(t_epikong *ekg, SDL_Event *event);
void			handles_keyup(t_epikong *ekg, SDL_Event *event);
void			handles_event(t_epikong *ekg);
void			fill_animation_jazz(t_char *new);
void			add_to_herolist(t_epikong *ekg, int x, int y);
void			fill_animation_robotmonster(t_char *new);
void			add_to_monsterlist(t_epikong *ekg, int x, int y);
void			add_to_objectlist(t_epikong *ekg, int x, int y, char type);
void			init_game(t_epikong *ekg);
void			move_rightandleft(t_epikong *ekg);
void			gravity_hero(t_epikong *ekg);
void			move_space(t_epikong *ekg);
int			find_objs(t_object *obj, char type);
void			move_updown(t_epikong *ekg);
void			move_hero(t_epikong *ekg);
void			move_camera(t_epikong *ekg);
void			move_monster(t_epikong *ekg);
void			do_move(t_epikong *ekg);
void			epikong(void);

#endif /* !_EPIKONG_H_ */
