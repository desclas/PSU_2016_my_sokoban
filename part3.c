/*
** part3.c for  in /home/mathias/Bureau/soko
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Tue Dec 20 17:41:51 2016 Mathias
** Last update Tue Dec 20 21:54:09 2016 Mathias
*/

#include "h.h"

void start2(t_all *all)
{
  int i;

  i = 0;
  while (all->buff[i] != '\0')
    {
      if (all->buff[i] == 'P')
	all->player += 1;
      if (all->buff[i] == 'X')
	all->block += 1;
      if (all->buff[i] == 'O')
	all->goal += 1;
      i += 1;
    }
}

void player(t_all *all)
{
  while (all->buff[all->i] != 'P')
    all->i += 1;
  while (all->buff[all->i] != '\n')
    all->i -= 1;
  while (all->buff[all->i] != 'P')
    {
      all->i += 1;
      all->pl += 1;
    }
  all->line = 0;
}

void line(t_all *all)
{
  int i;

  i = 0;
  while (all->buff[i] != '\n')
    {
      all->line += 1;
      i += 1;
    }
}

int start(t_all *all, char *str)
{
  char c;

  while (all->st != 0 && all->st != -1)
    {
      all->st = read(all->fd, &c, 1);
      all->len += 1;
    }
  all->buff = malloc(sizeof(char) * all->len + 2);
  close(all->fd);
  all->fd = open(str, O_RDONLY);
  read(all->fd, all->buff, all->len + 1);
  start2(all);
  if (all->player != 1)
    return (1);
  if (all->block != all->goal)
    return (1);
  all->tabx = malloc(sizeof(int) * all->block);
  all->taby = malloc(sizeof(int) * all->block);
  start3(all);
  player(all);
  line(all);
  cpyst(all, str);
}

int inist(t_all *all, char *str)
{
  all->plmod = 0;
  all->len = 0;
  all->i = 0;
  all->pl = 0;
  all->st = 3;
  all->line = 0;
  all->block = 0;
  all->player = 0;
  all->goal = 0;
  all->fd = open(str, O_RDONLY);
  if (all->fd == -1)
    return (1);
  else
    start(all, str);
  return (0);
}
