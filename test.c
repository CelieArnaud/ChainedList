/*
** test.c for test in /home/lerest_m/Programmation/Piscine/Tek 2/cpp_d02a/ex00/
**
** Made by Mewen Le Reste
** Login   <mewen.lereste@epitech.eu>
**
** Started on  Tue Apr 18 12:12:45 2017 Mewen Le Reste
** Last update Tue Apr 18 15:21:32 2017 Mewen Le Reste
*/

#include <stdio.h>
#include "list.h"

void		list_dumper(void *value)
{
  int		*tmp;

  tmp = (int *)value;
  printf("%d\n", *tmp);
}

int		list_comparator(void *first, void *second)
{
  int		*tmpFirst;
  int		*tmpSecond;

  tmpFirst = (int *)first;
  tmpSecond = (int *)second;
  if (*tmpFirst > *tmpSecond)
    return (1);
  else if (*tmpFirst < *tmpSecond)
      return (-1);
  return (0);
}

int		main(void)
{
  int		i;
  int		j;
  int		k;
  int		l;
  List	list = NULL;

  i = 1;
  listAddFront(&list, &i);
  j = 2;
  listAddFront(&list, &j);
  k = 3;
  listAddFront(&list, &k);
  l = 4;
  listAddFront(&list, &l);
  listDump(list, list_dumper);
  listDelete(&list);
  return (0);
}
