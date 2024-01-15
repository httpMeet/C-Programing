#include <stdio.h>
int fib(int n)
{
    if (n <= 1)
    return n;
    return fib(n - 1) + fib(n - 2);
}

void printFibSeries(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fib(i));
    }
}

int main()
{
    int n;

    printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci Series up to %d terms: ", n);
    printFibSeries(n);

    return 0;
}
