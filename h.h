/*
** h.h for  in /home/mathias/Bureau/soko
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Thu Dec 15 14:06:09 2016 Mathias
** Last update Tue Dec 20 21:49:30 2016 Mathias
*/

#ifndef H_H_
# define H_H_

# include <ncurses.h>
# include <termios.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_all
{
  char *res;
  int fd;
  int len;
  int i;
  int pl;
  int plmod;
  int input;
  int st;
  char *buff;
  int line;
  int *tabx;
  int *taby;
  int block;
  int goal;
  int player;
  int counter;
}		t_all;

void my_move(t_all *all, int check);
void move_up_space(t_all *all);
void move_up_box(t_all *all);
void move_up(t_all *all);
void move_down_space(t_all *all);
void move_down_box(t_all *all);
void move_down(t_all *all);
void move_right(t_all *all);
void move_left(t_all *all);
void start3(t_all *all);
void start2(t_all *all);
void player(t_all *all);
void line(t_all *all);
int start(t_all *all, char *str);
int inist(t_all *all, char *str);
void check_goal(t_all * all);
int check_win(t_all *all);
int choice(t_all *all);
void in_wind(t_all *all);
void reset(t_all *all);
void cpyst(t_all *all, char *str);

#endif /* !H_H_ */
