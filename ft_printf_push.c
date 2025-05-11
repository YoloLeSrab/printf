
#include "ft_printf.h"

// function to push a str (strdup it) dans la list, s'arrete a NULL pour stop process en cas d'erreur
t_printf *ft_push_str(char *s, t_printf **lst) //returns NULL if probleme
{
    t_printf *new;
    char    *new_str;
    int     i;

    i = ft_strlen(s);
    //chaine vide, return list without change
    if (i == 0)
        return (*lst);
    new_str = ft_strldup(s, i);
    if (new_str == NULL)
        return (NULL);
    new = ft_listnew(new_str);
    if (new == NULL)
    {
        free(new_str);
        return new;
    }
    new->str_len = i;
    ft_listadd_back(lst, new);
    *lst = new;
    return (*lst);
}

// function to push a car (strdup it) dans la list, s'arrete a NULL pour stop process en cas d'erreur
t_printf *ft_push_char(char c, t_printf **lst)
{
    t_printf *new;
    char *new_str;

    new_str = ft_strldup(&c, 1);
    if (new_str == NULL)
        return (NULL);
    new = ft_listnew(new_str);
    if (new == NULL)
    {
        free(new_str);
        return new;
    }
    new->str_len = 1;
    ft_listadd_back(lst, new);
    *lst = new;
    return (*lst);
}
t_printf *ft_push_nbr(long long int nb, char *base, int b, t_printf **lst) //takes the nbr, the base, maybe base_len, and list)S
{
    t_printf *new;
    char *result;

    result = ft_nbr_to_str_base(nb, base, b);
    if (result == NULL)
        return (NULL);
    new = ft_push_str(result, lst);
    free(result);
    return(new);
}

t_printf *ft_push_ptr(long long int nb, char *base, int b, t_printf **lst) //takes the nbr, the base, maybe base_len, and list)S
{
    t_printf *new;
    char *result;

    new = ft_push_str("0x", lst);
    if (new == NULL)
        return (NULL);
    result = ft_nbr_to_str_base(nb, base, b);
    if (result == NULL)
        return (NULL);
    new = ft_push_str(result, lst);
    free(result);
    return(new);
}
