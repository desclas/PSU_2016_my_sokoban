/*
** part2.c for  in /home/mathias/Bureau/soko
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Tue Dec 20 17:39:25 2016 Mathias
** Last update Tue Dec 20 21:58:09 2016 Mathias
*/

#include "h.h"

void move_down_box(t_all *all)
{
  my_move(all, 1);
  all->i += all->pl;
  if (all->buff[all->i] != '#')
    {
      all->buff[all->i] = 'X';
      my_move(all, 0);
      all->i -= 1;
      my_move(all, 0);
      all->i += all->pl;
      all->buff[all->i] = 'P';
      my_move(all, 0);
      all->i -= 1;
      my_move(all, 0);
      all->i += all->pl;
      all->buff[all->i] = 32;
      my_move(all, 3);
    }
  else
    my_move(all, 2);
}

void move_down(t_all *all)
{
  my_move(all, 1);
  all->i += all->pl;
  if (all->buff[all->i] == ' ' || all->buff[all->i] == 'O')
    move_down_space(all);
  else if (all->buff[all->i] == '#')
    my_move(all, 2);
  else if (all->buff[all->i] == 'X')
    move_down_box(all);
  else
    my_move(all, 2);
}

void move_right(t_all *all)
{
  if (all->buff[all->i + 1] == ' ' || all->buff[all->i] == 'O')
    {
      all->buff[all->i + 1] = 'P';
      all->buff[all->i] = 32;
      all->i += 1;
      all->pl += 1;
    }
  else if (all->buff[all->i + 1] == 'X')
    if (all->buff[all->i + 2] !='#')
      {
	all->buff[all->i + 2] = 'X';
	all->buff[all->i + 1] = 'P';
	all->buff[all->i] = ' ';
	all->i += 1;
	all->pl += 1;
      }
}

void move_left(t_all *all)
{
  if (all->buff[all->i - 1] == ' ' || all->buff[all->i] == 'O')
    {
      all->buff[all->i - 1] = 'P';
      all->buff[all->i] = 32;
      all->i -= 1;
      all->pl -= 1;
    }
  else if (all->buff[all->i - 1] == 'X')
    if (all->buff[all->i - 2] != '#')
      {
	all->buff[all->i - 2] = 'X';
	all->buff[all->i - 1] = 'P';
	all->buff[all->i] = ' ';
	all->i -= 1;
	all->pl -= 1;
      }
}

void start3(t_all *all)
{
  int i;
  int stock;
  int pos;

  pos = 0;
  stock = 0;
  i = 0;
  while (all->buff[i] != '\0')
    {
      if (all->buff[i] == 'O')
	{
	  all->tabx[pos] = stock;
	  all->taby[pos] = all->line;
	  pos += 1;
	}
      if (all->buff[i] == '\n')
	{
	  all->line += 1;
	  stock = 0;
	}
      stock += 1;
      i += 1;
    }
  all->line = 0;
}
