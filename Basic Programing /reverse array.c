#include <stdio.h>

int main(){

    int n, i;

    printf("Enter the number:");
    scanf("%d",&n);

    int arr[n];

    printf("List %d number:",n);
    for(i=0;i<n;i++){
    scanf ("%d", &arr[i]);
    }

printf("The reverse value is :");
for(i=n-1;i>=0;i--){
    printf("%d", arr[i]);
}
    
}