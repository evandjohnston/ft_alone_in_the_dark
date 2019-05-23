#include <stdio.h>
#include <stdlib.h>

int        *ft_range(int start, int end)
{
    int *result;
    int s_tot = start;
    int e_tot = end;

    if (start == 0 && end == 0) //passes (0, 0);
    {
        result = (int*)malloc(sizeof(int) * (s_tot + 1));
        result[s_tot] = s_tot;
        printf("%d start and end are zero\n", result[s_tot]);
        return (result);
    }
    if (start == end) // passes (1, 1);
    {
        result = (int*)malloc(sizeof(int) * (s_tot + 1));
        result[s_tot] = s_tot;
        printf("%d start equal to end\n", result[s_tot]);
        return (result);
    }
    if (start < end) //passes (1, 3).  passes (-1, 2).
    {
        while (s_tot < end)
            s_tot++;
        result = (int*)malloc(sizeof(int) * (s_tot + 1));
        s_tot = start;
        while (s_tot <= end)
        {
            result[s_tot] = s_tot;
            printf("%d start less than end\n", result[s_tot]);
            s_tot++;
        }
    }
    if (start > end) //passes (0, -3)
    {
        while (e_tot > start)
            e_tot++;
        e_tot = e_tot * -1;
        result = (int*)malloc(sizeof(int) * (e_tot + 1));
        e_tot = end;
        while (s_tot >= end)
        {
            result[s_tot] = s_tot;
            printf("%d start greater than end\n", result[s_tot]);
            s_tot--;
        }
    }
    return (result);
}

int        main()
{
    int i = 0;
    int j = -3;

    ft_range(i, j);
    return (0);
}