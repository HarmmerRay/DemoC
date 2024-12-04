#include <stdio.h>
//
// Created by 26247 on 11/17/2024.
//
int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(a) / sizeof(int);

    printf("%p\n", (void*)a);
    printf("%d\n", *a);
    printf("%d\n", *(a+1));
}