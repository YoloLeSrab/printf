
#include "ft_printf.h"

typedef struct          s_flags
{
   int	justify;
   int	pading;
   int	precision;
   int	width;
   int   length;
}                       t_flags;

//return 1 is format valid, else 0
int ft_is_format_valid(const char *format, va_list *aq);

//return length parsed, 0 if ERROR
int ft_check_format_bonus(char *format, va_list ap, t_printf **lst);

//redirect when arg +
int	ft_check_format_align(char c, va_list ap, t_printf **lst, char p);

int ft_check_format_prefix(char c, va_list ap, t_printf **lst);

int ft_is_convertible(char c);

int	ft_is_flag_valid(char *format);

int	ft_fill_flags_justify(t_flags *flags, char *format);

int	ft_fill_flags_padding(t_flags *flags, char *format);

int	ft_str_to_nb(char *str);

int	ft_fill_flags_width(t_flags *flags, char *format);

int	ft_fill_flags_precision(t_flags *flags, char *format);

t_flags *ft_init_flags(char *format);

int ft_check_format_flags(); // TODO TODO
