#include <stdio.h>

int main(){

    int i,n,key,found=0;

    printf("Enter the total no:");
    scanf("%d",&n);

    int arr[n];


    printf("List the %d number:",n);

    for(i=0;i<n;i++){

        scanf("%d", &arr[i]);

    }

    printf("Enter the element to search:");
    scanf("%d",&key);

    for(i=0;i<n;i++){
        if(arr[i]==key){
            found=1;
            break;
        }

    }

if(found ==1){
    printf("The Element %d found in %d", key,i+1);
}


else

printf("The Element %d is not found", key);

return 0;

}