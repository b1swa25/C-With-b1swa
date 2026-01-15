#include <stdio.h>

int main(){

    int i,n, odd =0, even=0;

    printf("Enter the Total number:");
    scanf("%d", &n);

    int arr[n];

    printf("The listed %d num are:", n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);

        if(arr[i] % 2 ==0){
            even ++;
        }
            else
                odd++;
        
    }
    printf("The odd number are: %d",odd);
    printf("The even number are: %d",even);

    return 0; 
}