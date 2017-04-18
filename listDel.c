/*
** listDel.c for List in /home/lerest_m/Programmation/Piscine/Tek 2/cpp_d02a/ex00/
**
** Made by Mewen Le Reste
** Login   <mewen.lereste@epitech.eu>
**
** Started on  Tue Apr 18 10:00:59 2017 Mewen Le Reste
** Last update Tue Apr 18 15:18:08 2017 Mewen Le Reste
*/

#include <stdio.h>
#include "list.h"

static t_bool	listDel(List *head, t_node *element)
{
  t_node	*node;
  t_node	*tmp;

  if (!element)
    return FALSE;
  node = *head;
  if (*head == element)
    {
      *head = element->next;
      free(node);
      return TRUE;
    }
  while (node->next != element)
    node = node->next;
  tmp = node->next;
  node->next = element->next;
  free(tmp);
  return TRUE;
}

t_bool		listDelFront(List *head)
{
  return listDel(head, listGetNode(head, 0));
}

t_bool		listDelBack(List *head)
{
  return listDel(head,
			  listGetNode(head, (listSize(*head) - 1)));
}

t_bool		listDelPosition(List *head, unsigned int position)
{
  return listDel(head, listGetNode(head, position));
}
