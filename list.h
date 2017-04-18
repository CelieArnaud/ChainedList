/*
** list.h for List in /home/lerest_m/Programmation/C/List/
**
** Made by Mewen Le Reste
** Login   <mewen.lereste@epitech.eu>
**
** Started on  Tue Apr 18 12:15:10 2017 Mewen Le Reste
** Last update Tue Apr 18 15:17:39 2017 Mewen Le Reste
*/

#ifndef LIST_H_
# define LIST_H_

# include <stdlib.h>
# include <stdbool.h>

typedef enum		e_bool
{
    FALSE,
    TRUE
}			t_bool;

typedef struct		s_node
{
    void		*value;
    struct s_node	*next;
}			t_node;

typedef t_node		*List;

typedef void		(*listDumpFct)(void *);
typedef int		(*listCmpFct)(void *, void *);

unsigned int		listSize(List);
t_bool			listIsEmpty(List);
void			listDelete(List *);
void			listDump(List, listDumpFct);

t_bool			listAddFront(List *, void *);
t_bool			listAddBack(List *, void *);
t_bool			listAddPosition(List *, void *, unsigned int);

t_bool			listDelFront(List *);
t_bool			listDelBack(List *);
t_bool			listDelPosition(List *, unsigned int);

t_node			*listGetFirstOf(List *, void *, listCmpFct);
t_node			*listGetNode(List *, unsigned int);
void			*listGetFront(List *);
void			*listGetBack(List *);
void			*listGetPosition(List *, unsigned int);

#endif /* !LIST_H_ */
