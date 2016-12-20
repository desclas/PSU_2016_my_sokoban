/*
** part1.c for  in /home/mathias/Bureau/soko
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Tue Dec 20 17:38:06 2016 Mathias
** Last update Tue Dec 20 20:24:52 2016 Mathias
*/

#include "h.h"

void my_move(t_all *all, int check)
{
  if (check == 0)
    while (all->buff[all->i] != '\n')
      all->i -= 1;
  if (check == 1)
    while (all->buff[all->i] != '\n')
      all->i += 1;
  if (check == 2)
    while (all->buff[all->i] != 'P')
      all->i -= 1;
  if (check == 3)
    while (all->buff[all->i] != 'P')
      all->i += 1;
}

void move_up_space(t_all *all)
{
  all->buff[all->i] = 'P';
  my_move(all, 1);
  all->i += all->pl;
  all->buff[all->i] = 32;
  my_move(all, 2);  
}

void move_up_box(t_all *all)
{
  my_move(all, 0);
  if (all->i > all->line)
    {
      all->i -= 1;
      my_move(all, 0);
      all->i += all->pl;
      if (all->buff[all->i] != '#')
	{
	  all->buff[all->i] = 'X';
	  my_move(all, 1);
	  all->i += all->pl;
	  all->buff[all->i] = 'P';
	  my_move(all, 1);
	  all->i += all->pl;
	  all->buff[all->i] = 32;
	  my_move(all, 2);
	}
      else
	my_move(all, 3);
    }
  else
    my_move(all, 3);
}

void move_up(t_all *all)
{
  my_move(all, 0);
  all->i -= 1;
  if (all->i > all->line)
    {
      my_move(all, 0);
      all->i += all->pl;
      if (all->buff[all->i] == ' ' || all->buff[all->i] == 'O')
	move_up_space(all);
      else if (all->buff[all->i] == '#')
	my_move(all, 3);
      else if (all->buff[all->i] == 'X')
	move_up_box(all);
    }
  else
    my_move(all, 3);
}

void move_down_space(t_all *all)
{
  all->buff[all->i] = 'P';
  my_move(all, 0);
  all->i -= 1;
  my_move(all, 0);
  all->i += all->pl;
  all->buff[all->i] = 32;
  my_move(all, 3);
}
