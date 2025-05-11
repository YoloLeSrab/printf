#include "ft_printf.h"

void    ft_listadd_back(t_printf **lst, t_printf *new)
{
    t_printf *temp;

    if (new == NULL)
    {
        return ;
    }
    if (*lst == NULL)
    {
        *lst = new;
        return ;
    }
    temp = *lst;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
}

t_printf *ft_listget_first(t_printf *lst)
{
    if (lst == NULL || lst->prev == NULL)
    {
        return (lst);
    }
    while (lst->prev != NULL)
    {
        lst = lst->prev;
    }
    return (lst);
}

t_printf *ft_listnew(char *str)
{
    t_printf *new;

    new = malloc(sizeof(t_printf));
    new->str = str;
    new->prev = NULL;
    new->next = NULL;

    return (new);
}
