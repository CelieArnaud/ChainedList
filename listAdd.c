/*
** listAdd.c for List in /home/lerest_m/Programmation/Piscine/Tek 2/cpp_d02a/ex00/
**
** Made by Mewen Le Reste
** Login   <mewen.lereste@epitech.eu>
**
** Started on  Tue Apr 18 09:57:38 2017 Mewen Le Reste
** Last update Tue Apr 18 15:18:02 2017 Mewen Le Reste
*/

#include "list.h"

static t_node	*getNewNode(void *elem)
{
  t_node	*new_elem;

  if ((new_elem = malloc(sizeof(t_node))) == NULL)
    return NULL;
  new_elem->value = elem;
  new_elem->next = NULL;
  return new_elem;
}

static List	listInit(void *elem)
{
  t_node	*new_element;

  if ((new_element = getNewNode(elem)) == NULL)
    return NULL;
  return new_element;
}

t_bool		listAddFront(List *head, void *elem)
{
  t_node	*new_element;

  if (*head == NULL)
    {
      if ((*head = listInit(elem)) == NULL)
	return FALSE;
      return TRUE;
    }
  if ((new_element = getNewNode(elem)) == NULL)
    return FALSE;
  new_element->next = *head;
  *head = new_element;
  return TRUE;
}

t_bool		listAddBack(List *head, void *elem)
{
  t_node	*old_element;

  if (*head == NULL)
    {
      if ((*head = listInit(elem)) == NULL)
	return FALSE;
      return TRUE;
    }
  old_element = *head;
  while (old_element->next != NULL)
    old_element = old_element->next;
  if ((old_element->next = getNewNode(elem)) == NULL)
    return FALSE;
  return TRUE;
}

t_bool		listAddPosition(List *head, void *elem,
				  unsigned int position)
{
  unsigned int	n;
  t_node	*new_element;
  t_node	*old_element;

  n = 1;
  if (position == 0)
    return listAddFront(head, elem);
  if (*head == NULL)
    return FALSE;
  old_element = *head;
  while (n < position && old_element->next != NULL)
    {
      old_element = old_element->next;
      ++n;
    }
  new_element = old_element->next;
  if (n != position || (old_element->next = getNewNode(elem)) == NULL)
    return FALSE;
  old_element->next->next = new_element;
  return TRUE;
}
