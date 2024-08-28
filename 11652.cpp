#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    long long int num1 = *(long long int *)a;
    long long int num2 = *(long long int *)b;
    if (num1 < num2)
        return -1;
    if (num1 >= num2)
        return 1;
}

long long int a[111111];

int main()
{
    int i, N, temp, count = 1;
    long long max_num = 0, max_count = 0;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%lld", &a[i]);
    }

    qsort(a, N, sizeof(long long int), compare);

    max_num = a[0];
    max_count = count = 1;
    for (i = 1; i < N; i++)
    {
        if (a[i - 1] == a[i])
        {
            count++;
        }
        else
        {
            if (max_count < count)
            {

                max_count = count;
                max_num = a[i - 1];
            }
            count = 1;
        }
    }
    if (max_count < count)
    {

        max_count = count;
        max_num = a[N - 1];
    }
    printf("%lld\n", max_num);
    return 0;
}