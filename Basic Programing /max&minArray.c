#include <stdio.h>

int main(){

    int i,n, max,min;

    printf("Enter the total number:");
    scanf("%d",&n);

    int arr[n];

    printf("List the %d number:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        
    }
    max=arr[0];
        min=arr[0];

        for(i=1;i<n;i++){
            if(arr[i]>max)
            max= arr[i];
            if(arr[i]<min)
            min= arr[i];
        }

    printf("The largest is %d:",max);
    printf("The smallest is %d:",min);

}