/*
** test.c for  in /home/mathias/Bureau/soko
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Wed Dec 14 17:16:23 2016 Mathias
** Last update Tue Dec 20 22:10:55 2016 Mathias
*/

#include "h.h"

void all_free(t_all *all)
{
  close(all->fd);
  free(all->res);
  free(all->tabx);
  free(all->taby);
  free(all->buff);
  free(all);
}

void mod_help()
{
  write(1, "USAGE\n\t./my_sokoban map\n\nDESCRIPTION\n\tmap\t", 43);
  write(1, "file representing the warehouse map, containing '#'", 51);
  write(1, " for walls,\n\t\t'P' for the player, 'X' for the boxes", 51);
  write(1, " and 'O' for storage locations.\n", 32);
}

int check_maps(t_all *all)
{
  int i;

  i = 0;
  while (all->buff[i] != '\0')
    {
      if (all->buff[i] != '#' && all->buff[i] != ' ' && all->buff[i] != 'O'
	  && all->buff[i] != 'X' && all->buff[i] != '\n'
	  && all->buff[i] != '\0' && all->buff[i] != 'P')
	return (1);
      i += 1;
    }
  return (0);
}

int main(int av, char **ac, char **env)
{
  t_all *all;

  if (av == 2 && ac[1][0] != '-' && ac[1][1] != 'h')
    {    
      all = malloc(sizeof(*all));
      if (inist(all, ac[1]) == 1)
	return (84);
      if (check_maps(all) == 1)
	return (84);
      initscr();
      noecho();
      in_wind(all);
      echo();
      endwin();
      all_free(all);
      return (0);
    }
  else if (av == 2 && ac[1][0] == '-' && ac[1][1] == 'h')
    {
      mod_help();
      return (0);
    }
  return (84);
}
