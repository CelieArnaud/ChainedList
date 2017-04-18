/*
** listGet.c for List in /home/lerest_m/Programmation/Piscine/Tek 2/cpp_d02a/ex00/
**
** Made by Mewen Le Reste
** Login   <mewen.lereste@epitech.eu>
**
** Started on  Tue Apr 18 10:04:43 2017 Mewen Le Reste
** Last update Tue Apr 18 15:18:13 2017 Mewen Le Reste
*/

#include <stdio.h>
#include "list.h"

t_node		*listGetNode(List *list, unsigned int position)
{
  t_node	*node;

  if (!list || position >= listSize(*list))
    return NULL;
  node = *list;
  while (position != 0)
    {
      node = node->next;
      --position;
    }
  return node;
}

void		*listGetFront(List *list)
{
  t_node	*node;

  if ((node = listGetNode(list, 0)) == NULL)
    return NULL;
  return node->value;
}

void		*listGetBack(List *list)
{
  t_node	*node;

  if ((node = listGetNode(list, listSize(*list))) == NULL)
    return NULL;
  return node->value;
}

void		*listGetPosition(List *list, unsigned int position)
{
  t_node	*node;

  if ((node = listGetNode(list, position)) == NULL)
    return NULL;
  return node->value;
}

t_node		*listGetFirstOf(List *list, void *value, listCmpFct val_comp)
{
  t_node	*node;

  if (list == NULL)
    return 0;
  node = *list;
  while (node->next != NULL)
    {
      if (val_comp(node->value, value) == 0)
	return node;
      node = node->next;
    }
  return NULL;
}
