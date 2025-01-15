#include    "minitalk.h"

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
            len++;
    return (len);
}

int ft_atoi(const char *str)
{
    int num;
    int neg;

    num = 0;
    neg = -1;
    while (*str == ' ' || *str == '\t')
}