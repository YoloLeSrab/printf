
#include "ft_printf.h"

char *ft_strldup(char *str, int len)
{
    char *new_str;
    int i;

    if (str == NULL || len == 0)
    {
        return (NULL);
    }
    new_str = malloc(sizeof(char) * len + 1);
    if (new_str == NULL)
    {
        return (NULL);
    }
    i = 0;
    while (i < len)
    {
        new_str[i] = str[i];
        i ++;
    }
    new_str[i] = '\0';
    return (new_str);
}

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        i ++;
    }
    return (i);
}

int ft_get_nbr_size(long long int nb, int base_len)
{
	int size;

	size = 0;
	while (nb > 0)
    {
        size ++;
        nb = nb / base_len;
    }
	return (size);
}

char *ft_nbr_to_str_base(long long int nb, char *base, int b)
{
    char *result;
    int size;
    int neg_check;

    if (nb == 0)
        return (ft_strldup("0", 1));
    neg_check = 0;
    if (nb < 0)
    {
        nb = nb * -1;
        neg_check = 1;
    }
    size = ft_get_nbr_size(nb, b);
    result = malloc(sizeof(char) * size + 1 + neg_check);
    if (result == NULL)
        return (NULL);
    if (neg_check)
        result[0] = '-';
    result[size + neg_check] == '\0';
    while (nb > 0)
    {
        result[--size + neg_check] = base[nb % b];
        nb = nb / b;
    }
    return(result);
}
