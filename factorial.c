#include<stdio.h>
#include<conio.h>

int fact(int n)
{
    if (n==1){
        return 1;
    }
    else{
        
        return n*fact(n-1);
    }
}

void main()
{
    int c = fact(5);
    printf("Factorial is:%d",c);
}

