/*
** simple_list.c for simple_list in /home/lerest_m/EPITECH/Tek2/Piscine/cpp_d02a/ex00/
**
** Made by Mewen Le Reste
** Login   <lerest_m@epitech.eu>
**
** Started on  Thu Jan  5 15:48:43 2017 Mewen Le Reste
** Last update Tue Apr 18 15:17:56 2017 Mewen Le Reste
*/

#include "list.h"

unsigned int	listSize(List list)
{
  unsigned int	n;
  t_node	*node;

  if (list == NULL)
    return 0;
  n = 1;
  node = list;
  while (node->next != NULL)
    {
      node = node->next;
      ++n;
    }
  return n;
}

t_bool		listIsEmpty(List list)
{
  if (list == NULL)
    return TRUE;
  return FALSE;
}

void		listDump(List list, listDumpFct val_disp)
{
  t_node	*node;

  if (list == NULL)
    return ;
  node = list;
  while (node->next != NULL)
    {
      val_disp(node->value);
      node = node->next;
    }
  val_disp(node->value);
}

void		listDelete(List *list)
{
  t_node	*node;

  node = *list;
  if (node->next != NULL)
    listDelete(&node->next);
  free(node);
}
