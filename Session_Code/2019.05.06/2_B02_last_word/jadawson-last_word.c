#include <unistd.h>

void     ft_putchar(char c)
{
     write(1, &c, 1);
}

void    last_word(char *str)
{
    int j;
    int i;
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            if (str[i + 1] >= 33 && str[i + 1] <= 126))
                j = i + 1;
        }
        i++;
    }
    while (str[j] >= 33 && str[j] <= 126)
    {
       ft_putchar(str[j]);
        j++;
    }
}
int        main(int argc, char **argv)
{
    if (argc == 2)
        last_word(argv[1]);
    write(1, "\n", 1);
    return (0);
}