#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

//struct declaration

typedef struct          s_printf
{
    char                *str;
    int                 str_len;
    struct s_printf     *prev;
    struct s_printf     *next;
}                       t_printf;

//ft_printf_format

void ft_read_format(char *format, va_list *ap, t_printf **lst);
int  ft_check_format(char c, va_list ap, t_printf **lst);


//ft_printf_list

t_printf    *ft_listnew(char *str);
void        ft_listadd_back(t_printf **lst, t_printf *new);
t_printf    *ft_listget_first(t_printf *lst);
//todo -> func to clear list (free mallocs)


//ft_printf_push

t_printf *ft_push_str(char *s, t_printf **lst);  // <-- creates a struc and adds str (strdup) + len (could pass it) in it, add it to end of the list (lst + 1)
t_printf *ft_push_char(char c, t_printf **lst); // <-- same with char for utility
t_printf *ft_push_nbr(long long int nb, char *base, int b, t_printf **lst);
t_printf *ft_push_ptr(long long int nb, char *base, int b, t_printf **lst);


//ft_printf_utils

char    *ft_strldup(char *str, int len);
int     ft_strlen(char *s);
char    *ft_nbr_to_str_base(long long int nb, char *base, int b);
int     ft_get_nbr_size(long long int nb, int base_len);


//ft_printf_write

int ft_write(t_printf *lst); // my function responsible for writing, has to be able to stop


//ft_printf

int ft_printf(const char *format, ...);


//if format[i] == '%' -> avance de int = ft_check_format -> interpreter format -> add to list
//else :
//       count caracs
//       strdup -> ft_listadd_back


//TODO ??//
//BONUS//
// function called on char '%', reads the line to substract the valid part of the string to read as a format

#endif

//NEED TO STOP WHEN ENCOUNTERING NULL

// + would be good to make ft_listadd_back faster
// = double chained list ? + ft_listget_first

// - une fonction qui prend une str et une len et une list et qui add back a la list ?
