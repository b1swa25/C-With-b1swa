#include <stdio.h>

int main(){

    int n,i;
    float sum = 0, average;

    printf("Enter the number:");
    scanf("%d",&n);

    int arr[n];

    printf("Enter %d the number:", n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    
    }
    average = sum / n;

printf("The the value of sum is : %.2f",sum);
printf("The vale of average is : %.2f", average);
return 0;

}