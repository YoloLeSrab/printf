
#include "ft_printf.h"
#include "ft_printf_bonus.h"

int ft_printf(const char *format, ...)
{
    va_list ap;
    va_list aq;
    t_printf *lst;
    int i;

    va_start(ap, format);
    va_copy(aq, ap);
    //TODO func to check if str valid
    if(!(ft_is_format_valid(format, &aq)))
    {
        va_end(ap);
        va_end(aq);
        return (0);
    }
    va_end(aq);
    lst = NULL;
    ft_read_format((char *)format, &ap, &lst);
    i = ft_write(ft_listget_first(lst));

    //clear lst
    va_end(ap);
    return (i);
}

void    test()
{
    ////////

    printf("%-.1s -\n", "42");
    printf("%.2s -\n", "42");
    printf("%0.3s -\n", "42");

    return ;
}

int main(void)
{

    int i;
    int j;
    char *str = "-0324d";

    // ' ' && '+'
    /*i = printf("wtf % i % d %+i %+d\n", 42, 42, 42, 42);
    printf(" = %d\n", i);
    j = ft_printf("wtf % i % d %+i %+d\n", 42, 42, 42, 42);
    printf(" = %d\n", j);*/

    // '#'

    /*i = printf("wtf %#x %#X but also % i % d %+i %+d\n", 42, 42, 42, 42, 42, 42);
    printf(" = %d\n", i);
    j = ft_printf("wtf %#x %#X but also % i % d %+i %+d\n", 42, 42, 42, 42, 42, 42);
    printf(" = %d\n", j);*/

    //test();

    t_flags *flags;

    if (ft_is_flag_valid(str))
    {
        printf("flag is valid\n");
    }
    else
    {
        printf("flag is NOT valid\n");
    }
    flags = ft_init_flags(str);
    if (flags == NULL)
        printf("flags is NULL");
    else
    {
        printf("justify : %d\n", flags->justify);
        printf("padding : %d\n", flags->pading);
        printf("width : %d\n", flags->width);
        printf("precision : %d\n", flags->precision);
        printf("length : %d\n", flags->length);
        free(flags);
    }
    return (0);
}
