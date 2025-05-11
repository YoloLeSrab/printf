#include "ft_printf.h"

//avance dans la chaine et imprime chaque str, stops at NULL
int ft_write(t_printf *lst)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (lst != NULL && count != -1)
    {
        i = write(1, lst->str, lst->str_len);
        if (i == -1)
        {
            count = -1;
        }
        else
        {
            count = count + i;
        }
        lst = lst->next;
    }
    return (count);
}
