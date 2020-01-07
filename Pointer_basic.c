#include <stdio.h>

void swapp(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int a,b;
    a=10;
    b=20;
    printf("Before Swapping a = %d and b = %d",a,b);
    swapp(&a,&b);
    printf("After Swapping a = %d and b = %d",a,b);
    return 0;
}
