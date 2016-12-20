/*
** part4.c for  in /home/mathias/Bureau/soko
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Tue Dec 20 21:30:44 2016 Mathias
** Last update Tue Dec 20 22:30:11 2016 Mathias
*/

#include "h.h"

void check_goal(t_all * all)
{
  int i;
  int count;
  int line;

  line = 0;
  count = 0;
  i = 0;
  while (count != all->goal)
    {
      while (line != all->taby[count])
	{
	  i += 1;
	  if (all->buff[i] == '\n')
	    line += 1;
	}
      i += all->tabx[count];
      if (all->buff[i] == ' ')
	all->buff[i] = 'O';
      i -= all->tabx[count];
      count += 1;
    }
}

int check_win(t_all *all)
{
  int i;
  int count;
  int line;

  all->counter = 0;
  i = 0;
  count = 0;
  line = 0;
  while (count != all->goal)
    {
      while (line != all->taby[count])
	{
	  i += 1;
	  if (all->buff[i] == '\n')
	    line += 1;
	}
      i += all->tabx[count];
      if (all->buff[i] != 'X')
	all->counter += 1;
      i -= all->tabx[count];
      count += 1;
    }
  if (all->counter == all->goal)
    return (0);
  return (1);
}

int choice(t_all *all)
{
  if (all->input == 'A')
    move_up(all);
  if (all->input == 'B')
    move_down(all);
  if (all->input == 'C')
    move_right(all);
  if (all->input == 'D')
    move_left(all);
  if (all->input == 32)
    reset(all);
  return (0);
}

void in_wind(t_all *all)
{
  while (check_win(all) != 1)
    {
      clear();
      check_goal(all);
      printw("%s", all->buff);
      refresh();
      all->input = getch();
      if (choice(all) == 1)
	break;
     }
  if (check_win(all) == 1)
    {
      clear();
      printw("you win. good game ^^");
      refresh();
      sleep(2);
    }
}
