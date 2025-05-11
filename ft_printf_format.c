
#include "ft_printf.h"
#include "ft_printf_bonus.h"

// coupler ft_check_format avec une fonction qui trouve le carac determinant ? // peut-être dans ft_read_format
// doit renvoyer le nombre de caracteres parsés, pour continuer la lecture plus loin
int ft_check_format(char c, va_list ap, t_printf **lst)
{
    t_printf *new;
    int len;

    if (c == 'c')
        new = ft_push_char(va_arg(ap, int), lst);
    else if (c == '%')
        new = ft_push_char('%', lst);
    else if (c == 's')
        new = ft_push_str(va_arg(ap, char *), lst);
    else if (c == 'i' || c == 'd' || c == 'u')
        new = ft_push_nbr((long long int)va_arg(ap, int), "0123456789", 10, lst);
    else if (c == 'x')
        new = ft_push_nbr((long long int)va_arg(ap, int), "0123456789abcdef", 16, lst);
    else if (c == 'X')
        new = ft_push_nbr((long long int)va_arg(ap, int), "0123456789ABCDEF", 16, lst);
    else if (c == 'p')
        new = ft_push_ptr((long long int)va_arg(ap, void *), "0123456789abcdef", 16, lst);
    else
        return (0);
    if (new == NULL)
        return (0);
    return (2);
}
//stop process si return 0;

int	ft_parse_format(char *format, int start, t_printf **lst)
{
	int len;
	char *parse;
	t_printf *current_lst;

	len = 0;
    while(format[start + len] && format[start + len] != '%')
        len ++;
            parse = ft_strldup(&format[start], len);
            if (parse == NULL)
                return (0);
            current_lst = ft_listnew(parse);
            if (current_lst == NULL)
            {
                free(parse);
                return (0);
            }
            current_lst->str_len = len;
            ft_listadd_back(lst, current_lst);
	return (len);
}

void ft_read_format(char *format, va_list *ap, t_printf **lst)
{
    int i;
    int len;

    i = 0;
    if (format == 0)
        return ;
    while(format[i])
    {
        if (format[i] == '%')
		{
            len = ft_check_format_bonus(&format[i + 1], *ap, lst); //remplacer format[i] par la str
			if (len == 0)
				return ;
			i += len;
			// new function below (return len)
		}
        else if (format[i])
        {
            len = ft_parse_format(format, i, lst);
			if (len == 0)
				return ;
            i += len;
        }
    }
}
