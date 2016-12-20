/*
** part5.c for  in /home/mathias/Bureau/soko
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Tue Dec 20 21:41:26 2016 Mathias
** Last update Tue Dec 20 22:23:35 2016 Mathias
*/

#include "h.h"

void reset(t_all *all)
{
  int i;

  i = 0;
  while (all->res[i] != '\0')
    {
      all->buff[i] = all->res[i];
      i += 1;
    }
  all->i = 0;
  all->pl = 0;
  player(all);
}

void cpyst(t_all *all, char *str)
{
  all->res = malloc(sizeof(char) * all->len + 2);
  all->fd = open(str, O_RDONLY);
  read(all->fd, all->res, all->len + 1);
  close(all->fd);
}
