#include <stdio.h>

int factorial(int n){
    if(n==0)
        return 1;
    else 
     return n*factorial(n-1);

}

int main(){

    int a=5;

    printf("factorial=%d", factorial(a));
    return 0;

}