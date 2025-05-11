
#include "ft_printf_bonus.h"

//TODO : return 1 is format valid, else 0 // use is flag valid and ft_is_convertible (att : % is missing)
int ft_is_format_valid(const char *format, va_list *aq)
{
	if (format == NULL)
	{
		return (0);
	}
	return (1);
}

int	ft_check_format_align(char c, va_list ap, t_printf **lst, char p)
{
	t_printf *new;
    int len;
	long long int lli;

	if (c == 'i' || c == 'd')
	{
		lli = (long long int)va_arg(ap, int);
		if (lli >= 0)
		{
			new = ft_push_char(p, lst);
			if (new == (NULL))
				return (0);
		}
        new = ft_push_nbr(lli, "0123456789", 10, lst);
	}
    else
        return (0);
    if (new == NULL)
        return (0);
    return (3);
}

int ft_check_format_prefix(char c, va_list ap, t_printf **lst)
{
	t_printf *new;
	int len;
	long long int lli;

	lli = (long long int)va_arg(ap, int);
	if (c == 'x')
	{
		new = ft_push_str("0x", lst);
		if (new == NULL)
			return (0);
		new = ft_push_nbr(lli, "0123456789abcdef", 16, lst);
	}
	else if (c == 'X')
	{
		new = ft_push_str("0X", lst);
		if (new == NULL)
			return (0);
		new = ft_push_nbr(lli, "0123456789ABCDEF", 16, lst);
	}
	else
		return (0);
	if (new == NULL)
		return (0);
	return (3);
}

int ft_is_convertible(char c)
{
	if (c == 'c' || c == 's' || c == 'u' || c == 'i' || c == 'd' || c == 'p'
		|| c == 'x' || c == 'X')
		{
			return (1);
		}
		return (0);
}

int	ft_is_flag_valid(char *format)
{
	int	i;

	i = 0;
	if (format[i] == '-')
		i ++;
	if (format[i] == '0')
		i ++;
	if (format[i] != '0')
	{
		while(format[i] >= '0' && format[i] <= '9')
			i ++;
	}
	if (format[i] == '.')
	{
		i ++;
		if (format[i] != '0')
		{
			while (format[i] >= '0' && format[i] <= '9')
				i ++;
		}
	}
	if (ft_is_convertible(format[i]))
		return (i + 1);
	return (0);
}

int	ft_fill_flags_justify(t_flags *flags, char *format)
{
	if (format[0] == '-')
	{
		flags->justify = 1;
		return (1);
	}
	return (0);
}

int	ft_fill_flags_padding(t_flags *flags, char *format)
{
	if (format[0] == '0')
	{
		flags->pading = 1;
		return (1);
	}
	return (0);
}

int	ft_str_to_nb(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = (result * 10) + str[i] - '0';
		i ++;
	}
	return (result) ;
}

int	ft_fill_flags_width(t_flags *flags, char *format)
{
	int	i;
	char *str;
	int	result;

	i = 0;
	while (format[i] >= '0' && format[i] <= '9')
		i ++;
	if (i == 0)
		return (0);
	str = ft_strldup(format, i);
	if (str == NULL)
		return (0);
	result = ft_str_to_nb(str);
	flags->width = result;
	free(str);
	return (i);
}

int	ft_fill_flags_precision(t_flags *flags, char *format)
{
	int i;
	char *str;
	int	result;

	i = 0;
	if (format[i] != '.')
		return (0);
	i ++;
	while (format[i] >= '0' && format[i] <= '9')
		i ++;
	str = ft_strldup(&format[1], i - 1);
	if (str == NULL)
		return (0);
	result = ft_str_to_nb(str);
	flags->precision = result;
	free(str);
	return (i);
}

t_flags *ft_init_flags(char *format)
{
	t_flags *flags;
	int	index;

	flags = malloc(sizeof(t_flags));
	if (flags == NULL)
		return (NULL);
	flags->justify = 0;
	flags->pading = 0;
	flags->width = 0;
	flags->precision = 0;
	index = 0;
	index += ft_fill_flags_justify(flags, format);
	index += ft_fill_flags_padding(flags, &format[index]);
	index += ft_fill_flags_width(flags, &format[index]);
	index += ft_fill_flags_precision(flags, &format[index]);
	flags->length = index + 1;
	return(flags);
}

int ft_check_format_flags() // TODO -> redirect based on the variable
{
	return (1);
}

//return length parsed, 0 if ERROR // send to corresponding check format
int ft_check_format_bonus(char *format, va_list ap, t_printf **lst)
{
	int	i;
	int len;
	t_flags *flags;

	i = 0;
	len = 0;
	if (format[i] == '+' || format[i] == ' ')
		len = ft_check_format_align(format[i + 1], ap, lst, format[i]);
	else if (ft_is_flag_valid(&format[i]))
	{
		flags = ft_init_flags(&format[i]);
		if (flags == NULL)
			return

		len = ft_check_format_flags();
		free(flags);
	}
	else if (format[i] == '#')
		len = ft_check_format_prefix(format[i + 1], ap, lst);
	else
		len = ft_check_format(format[i], ap, lst);
	return (len);
}
