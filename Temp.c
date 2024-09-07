#include <stdio.h>
#include <stdlib.h>

void main()
{
    int age = 43;
    int *ptr1 = &age;
    int **ptr2 = &ptr1;

    printf("age: %d\n",age);
    printf("&age: %p\n", &age);
    printf("ptr1: %p\n", ptr1);
    printf("*ptr1: %d\n", *ptr1);
    printf("**ptr2: %p\n", ptr2);
    printf("**ptr2: %d\n", **ptr2);

}
