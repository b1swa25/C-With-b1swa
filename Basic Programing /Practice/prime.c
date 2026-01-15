#include <stdio.h>

int isPrime(int n){

    if (n <= 1) {
        return 0;
    }

    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }

    return 1;
}

int main(){

    int n;

    printf("Enter the Number:");
    scanf("%d",&n);

    if(isPrime(n)){
        printf("Yes, The number is Prime number");
    }else{
        printf("No, The number is not prime Number");
    }

    return 0;

}